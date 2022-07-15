# SSandbox

# Build Guide
(MSVC only currently)

### Requirements:
- Visual Studio 2022
- OpenSSL (tested with 1.1)
- Boost (tested with 1.78)
- CMake

### Building
- git clone https://github.com/RawrBox/SSandbox.git
- mkdir build
- cd build
- cmake ..

- Open solution
- Right click project Install -> Build.
- Files should be in ./build/bin

## Releases: Without compiling
- Download latest release from https://github.com/RawrBox/SSandbox/releases
- Copy all files to the game root directory (NOT _beta_, _live_ or _ptr_).
- Unpack the zip file.
- Start SSandbox.exe.
- If you get a dll missing error install https://aka.ms/vs/17/release/vc_redist.x64.exe (Visual Studio Redist).

## After it starts
- Log in with any account/password you want. Creation not needed.
