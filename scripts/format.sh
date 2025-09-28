cd /home/guojifang/project/scivisualizer/src
find . -path ./base -prune -o -type f \( -name "*.cpp" -o -name "*.h" \) -exec \
/home/guojifang/.vscode/extensions/ms-vscode.cpptools-1.27.7-linux-x64/LLVM/bin/clang-format -i {} +