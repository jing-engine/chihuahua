clear
ndk-build -j
echo "Please rebuild and install APK"
adb logcat -c
adb logcat | grep Scene3D