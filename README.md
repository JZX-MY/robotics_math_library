# robotics_math_library
This C++ function library will implement some commonly used computational functions in robotics.



### 文件结构

```
/CoordinateTransform/
    |-- CMakeLists.txt         # CMake 配置文件
    |-- /include/
    |    |-- rob_math.h  # 头文件
    |-- /src/
    |    |-- rob_math.cpp  # 实现文件
    |    |-- main.cpp               # 测试文件
```


### How to Use

1. **创建构建目录**：
   在 `robotics_math_library` 目录下，创建 `build` 文件夹：
   ```bash
   mkdir build
   cd build
   ```

2. **运行 CMake**：
   在 `build` 目录中运行 CMake：
   ```bash
   cmake ..
   ```

3. **编译项目**：
   使用 `make` 命令编译：
   ```bash
   make
   ```

4. **运行可执行文件**：
   编译完成后运行生成的 `main` 文件：
   ```bash
   ./main
   ```



