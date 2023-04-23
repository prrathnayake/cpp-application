## Pre-requisites
+  [cpp-base](https://github.com/prrathnayake/cpp-base.git)
+  [cpp-tools](https://github.com/prrathnayake/cpp-tools.git)

## Usage
```
mkdir cpp
cd cpp
```

Clone all cpp-tools, cpp-base and cpp-application. Then check this repos to install their dependencies.
```
git clone https://github.com/prrathnayake/cpp-application.git
git clone https://github.com/prrathnayake/cpp-base.git
git clone https://github.com/prrathnayake/cpp-tools.git
```
Create packages using Conan2
```
python3 cpp-tools/module/scripts/buildBase.py ./cpp-base/ -p <package name>
```

To all create packages.
```
python3 cpp-tools/module/scripts/buildBase.py ./cpp-base/
```

Create binaries in cpp-application
```
cd cpp-application
conan build . --build=missing
```

Run binaries
```
./build/Release/bin/<binary name>
```