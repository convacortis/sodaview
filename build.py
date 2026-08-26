import sys
import subprocess
import os
import shutil
from pathlib import Path

script_dir = Path(__file__).parent.resolve()
# FOR FUTURE ---- build_type = "Release" if "--release" in sys.argv else "Debug"


def main():

    if sys.platform.startswith('linux'):
        linuxBuild()

    elif sys.platform == 'win32':
        winBuild()

    else:
        print("System: ", sys.platform, " currently not supported")




def compileShaders(): # in future could just pass platform tweaking whether glslc is found or glslc.exe is searched for
    glslc = shutil.which("glslc")

    if not glslc:
        print("glslc not installed or could not be found")
        return False
    else:
        print("found glslc: ", glslc)

    # Source directory containing raw .vert / .frag files
    shader_src_dir = script_dir / "sodaview/assets/shaders"
    
    # Target build directory for compiled .spv files
    shader_build_dir = script_dir / "build/shaders"
    shader_build_dir.mkdir(parents=True, exist_ok=True)

    print("Shader source directory: ", shader_src_dir)
    print("Shader build directory:  ", shader_build_dir)

    for shader_file in shader_src_dir.glob("*"):
        if shader_file.suffix in [".vert", ".frag", ".comp"]:
            # Output file becomes build/shaders/<filename>.<ext>.spv
            output_file = shader_build_dir / (shader_file.name + ".spv")

            if not output_file.exists() or shader_file.stat().st_mtime > output_file.stat().st_mtime:
                print("Compiling shader: ", shader_file.name, " -> ", output_file.name)

                result = subprocess.run([glslc, str(shader_file), "-o", str(output_file)], capture_output=True, text=True)

                if result.returncode != 0:
                    print("Shader error in ", shader_file.name, ":", result.stderr)
                    return False


def firstCMakeBuild():
    print("initial build")
    subprocess.run(["cmake", "-S", ".", "-B", "build", "-DCMAKE_EXPORT_COMPILE_COMMANDS=ON"])
    subprocess.run(["cmake", "--build", "build"])


def cmakeBuild():
    print("recompiling")
    subprocess.run(["cmake", "--build", "build"])




def linuxBuild():

    print("building for linux")


    if ((script_dir / "build").exists()):
        if ( compileShaders() == False ):
            print("shaders not compiled correctly")
            return
        else: 
            print("shaders successfully compiled")

        cmakeBuild()
    
    else:
        if ( compileShaders() == False ):
            print("shaders not compiled correctly")
            return
        else: 
            print("shaders successfully compiled")

        firstCMakeBuild()

    



def winBuild():
    print("Building for Windows")
    print("windows not currently supported - coming soon!")





if __name__ == "__main__":
    main()