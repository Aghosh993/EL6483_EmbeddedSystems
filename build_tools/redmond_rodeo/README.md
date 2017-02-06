# This is the Windows build system directory. Work in progress!!

## Quickstart:

Head over to https://msys2.github.io/ and download the appropriate installer.

Once the installer downloads, launch it. Just do a default installation, clicking "next" until you're done.

Once the installation is complete, download the ST-Link utility from http://www.st.com/en/embedded-software/stsw-link004.html. Click "Get software" at the top, and "Get software" under the "Order from ST" column at the bottom of the page.

(You may have to provide and verify your name/email for this stage. In that case a download link will be emailed to you be ST)

The download will be in the form of a Zip archive. Navigate to it in the file manager, right-click and select "Extract all". Follow the defaults. The folder will be extracted in the same directory, and will automatically be opened. Double-clock the installer and allow it to run if prompted. Go through the default options and keep clicking "next"/"continue" until the installer is finished. There will be a step where the installer will unpack and install some drivers. If prompted, allow the drivers to be installed/trusted.

Now, download the GCC ARM toolchain for Windows from: https://launchpad.net/gcc-arm-embedded/5.0/5-2016-q3-update/+download/gcc-arm-none-eabi-5_4-2016q3-20160926-win32.zip

Unzip this archive, and move the resulting folder to some directory on your machine. For the purpose of this procedure, let that directory be C:\Users\some_user\sandbox. Rename the GCC folder to "gcc-arm-none-eabi-5_4-2016q3".

Now, go to https://github.com/Aghosh993/EL6483_EmbeddedSystems and download the repository as a Zip file by selecting "Clone or Download" -> "Download ZIP"

Extract the resultant folder to "C:\Users\some_user\sandbox" when prompted to tell the unzip utility where to extract to (under "Files will be extraced to this folder:"). There should now be a "EL6483_EmbeddedSystems-master" folder within the sandbox folder. Rename it so there is no "-master" on the end.

Now, launch the MSYS Shell. Go to the Start menu, type "msys". The "MSYS2 MinGW 32-bit" option should pop up. Click it, and the shell will launch.

First, we will use the built-in package manager to update the system. Type "pacman -Syu". If prompted to allow installation, type Y" and then press Enter. Once the update is finished, you will be prompted to exit. Just close the window, and click "OK" if warned that a process is still running. Re-launch the Msys shell as mentioned before.

Once at the shell, type: "pacman -S make". If prompted to allow installation, type Y" and then press Enter. Once the command finishes and returns to the prompt, type: "cd C:\Users" then type: "cd some_user/sandbox/EL6483_EmbeddedSystems/build_tools/arctic_awesomeness".

Now, you should be able to auto-create a new project. Type: "./mkproject.sh test f3" (for F3 discovery) or "./mkproject.sh test f4" for the F4 Discovery board. This will automatically create a new project in a sub-folder called "test" with the necessary Makefile and source code.

Now, change directories into the test project by typing: "cd test". Build the code with "make". You will see a bunch of output, followed by an indication of the final size of the binary file containing the executable code.

Now you are ready to actually load the code onto the STM32 board. Connect it to your PC with a mini-USB cable. You should see a notification that the driver was successfully installed. Launch the ST-Link utility (you should be able to see it when you search for it from the Start menu). Go to "Target" and click "Connect". You should be connected to the board now. Go to "File"->"Open File" and navigate to C:\Users\some_user\sandbox\EL6483_EmbeddedSystems\build_tools\arctic_awesomeness\test. You should see "test.bin" as one of the available files. Select it and double-click. Now, go to "Target"->"Program" and click "Start". THe chip should be programmed and running the firmware. 

Any time you re-compile the code in a project, just re-open the binary using the above instructions, and re-flash. Enjoy!

(c) Abhimanyu Ghosh, 2016
