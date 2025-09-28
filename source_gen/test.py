import os
os.environ['QT_QPA_PLATFORM'] = 'xcb'
os.environ.pop('XDG_SESSION_TYPE', None)
import numpy as np
import matplotlib.pyplot as plt

from mpl_toolkits.mplot3d import Axes3D

plt.use('Qt5Agg')

class SimpleTCADSimulator:
    def __init__(self, length=1.0, width=1.0, height=1.0, nx=10, ny=10, nz=10):
        """
        初始化仿真器
        :param length: 器件长度(x方向)
        :param width: 器件宽度(y方向)
        :param height: 器件高度(z方向)
        :param nx: x方向网格点数
        :param ny: y方向网格点数
        :param nz: z方向网格点数
        """
        self.length = length
        self.width = width
        self.height = height
        self.nx = nx
        self.ny = ny
        self.nz = nz
        
        # 生成网格点坐标
        self.generate_mesh()
        
        # 生成连线信息
        self.generate_connections()
        
        # 初始化电场数据
        self.electric_field = np.zeros((nx, ny, nz, 3))
        
    def generate_mesh(self):
        """生成均匀网格点坐标"""
        x = np.linspace(0, self.length, self.nx)
        y = np.linspace(0, self.width, self.ny)
        z = np.linspace(0, self.height, self.nz)
        
        self.mesh_points = np.zeros((self.nx, self.ny, self.nz, 3))
        
        for i in range(self.nx):
            for j in range(self.ny):
                for k in range(self.nz):
                    self.mesh_points[i,j,k] = [x[i], y[j], z[k]]
    
    def generate_connections(self):
        """生成网格点之间的连线信息"""
        self.connections = []
        
        # 连接x方向的相邻点
        for i in range(self.nx-1):
            for j in range(self.ny):
                for k in range(self.nz):
                    self.connections.append(((i,j,k), (i+1,j,k)))
        
        # 连接y方向的相邻点
        for i in range(self.nx):
            for j in range(self.ny-1):
                for k in range(self.nz):
                    self.connections.append(((i,j,k), (i,j+1,k)))
        
        # 连接z方向的相邻点
        for i in range(self.nx):
            for j in range(self.ny):
                for k in range(self.nz-1):
                    self.connections.append(((i,j,k), (i,j,k+1)))
    
    def apply_voltage(self, voltage=1.0):
        """施加电压，计算简单电场分布"""
        for i in range(self.nx):
            for j in range(self.ny):
                for k in range(self.nz):
                    # 简单的线性电场模型
                    self.electric_field[i,j,k] = [
                        -voltage/self.length,  # Ex
                        0,                     # Ey
                        0                      # Ez
                    ]
    
    def visualize_mesh(self):
        """可视化网格结构"""
        fig = plt.figure(figsize=(10, 8))
        ax = fig.add_subplot(111, projection='3d')
        
        # 绘制网格点
        x = self.mesh_points[:,:,:,0].flatten()
        y = self.mesh_points[:,:,:,1].flatten()
        z = self.mesh_points[:,:,:,2].flatten()
        ax.scatter(x, y, z, c='b', marker='o')
        
        # 绘制连线
        for conn in self.connections:
            p1 = self.mesh_points[conn[0]]
            p2 = self.mesh_points[conn[1]]
            ax.plot([p1[0], p2[0]], [p1[1], p2[1]], [p1[2], p2[2]], 'k-', linewidth=0.5)
        
        ax.set_xlabel('X')
        ax.set_ylabel('Y')
        ax.set_zlabel('Z')
        ax.set_title('Device Mesh Structure')
        plt.show()
    
    def visualize_field(self, plane='xy', z_slice=0):
        """可视化电场分布"""
        if plane == 'xy':
            X, Y = np.meshgrid(
                np.linspace(0, self.length, self.nx),
                np.linspace(0, self.width, self.ny)
            )
            Ex = self.electric_field[:, :, z_slice, 0].T
            Ey = self.electric_field[:, :, z_slice, 1].T
            
            plt.figure(figsize=(8, 6))
            plt.quiver(X, Y, Ex, Ey)
            plt.title(f'Electric Field in XY Plane (z={z_slice})')
            plt.xlabel('X')
            plt.ylabel('Y')
            plt.show()
        
        elif plane == 'xz':
            X, Z = np.meshgrid(
                np.linspace(0, self.length, self.nx),
                np.linspace(0, self.height, self.nz)
            )
            Ex = self.electric_field[:, y_slice, :, 0].T
            Ez = self.electric_field[:, y_slice, :, 2].T
            
            plt.figure(figsize=(8, 6))
            plt.quiver(X, Z, Ex, Ez)
            plt.title(f'Electric Field in XZ Plane (y={y_slice})')
            plt.xlabel('X')
            plt.ylabel('Z')
            plt.show()



# 创建仿真器实例
simulator = SimpleTCADSimulator(length=1.0, width=1.0, height=0.5, nx=5, ny=5, nz=3)

# 施加1V电压
simulator.apply_voltage(voltage=1.0)

# 可视化网格结构
simulator.visualize_mesh()

# 可视化电场分布
simulator.visualize_field(plane='xy', z_slice=1)

# 输出一些数据
print("Mesh points shape:", simulator.mesh_points.shape)
print("Number of connections:", len(simulator.connections))
print("Electric field at (0,0,0):", simulator.electric_field[0,0,0])