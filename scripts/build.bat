@echo off

::Create build dir
set buildDir=%~dp0..\build
if not exist %buildDir% mkdir %buildDir%
pushd %buildDir%

::Create obj dir
set objDir=.\obj
if not exist %objDir% (
    mkdir %objDir%
    mkdir %objDir%\engine
    mkdir %objDir%\game
)

::Needed folder
set scriptDir=%~dp0..\scripts

::Use make to build target
cd %scriptDir%\
mingw32-make

popd