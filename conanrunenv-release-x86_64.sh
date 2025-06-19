script_folder="/home/pasan/PROJECTS/cpp/cpp-application"
echo "echo Restoring environment" > "$script_folder/deactivate_conanrunenv-release-x86_64.sh"
for v in LD_LIBRARY_PATH DYLD_LIBRARY_PATH PATH OPENSSL_MODULES
do
    is_defined="true"
    value=$(printenv $v) || is_defined="" || true
    if [ -n "$value" ] || [ -n "$is_defined" ]
    then
        echo export "$v='$value'" >> "$script_folder/deactivate_conanrunenv-release-x86_64.sh"
    else
        echo unset $v >> "$script_folder/deactivate_conanrunenv-release-x86_64.sh"
    fi
done


export LD_LIBRARY_PATH="/home/pasan/.conan2/p/libzi1780528f039e6/p/lib:/home/pasan/.conan2/p/libzid52a046e17cf7/p/lib:/home/pasan/.conan2/p/bzip21505bbbc20f2c/p/lib:/home/pasan/.conan2/p/xz_ut2397d8b52e1b6/p/lib:/home/pasan/.conan2/p/opens7abf84295e910/p/lib:/home/pasan/.conan2/p/zlib8781ef98e8c2c/p/lib:/home/pasan/.conan2/p/zstdf09cd57eedb9b/p/lib:$LD_LIBRARY_PATH"
export DYLD_LIBRARY_PATH="/home/pasan/.conan2/p/libzi1780528f039e6/p/lib:/home/pasan/.conan2/p/libzid52a046e17cf7/p/lib:/home/pasan/.conan2/p/bzip21505bbbc20f2c/p/lib:/home/pasan/.conan2/p/xz_ut2397d8b52e1b6/p/lib:/home/pasan/.conan2/p/opens7abf84295e910/p/lib:/home/pasan/.conan2/p/zlib8781ef98e8c2c/p/lib:/home/pasan/.conan2/p/zstdf09cd57eedb9b/p/lib:$DYLD_LIBRARY_PATH"
export PATH="/home/pasan/.conan2/p/libzid52a046e17cf7/p/bin:/home/pasan/.conan2/p/bzip21505bbbc20f2c/p/bin:/home/pasan/.conan2/p/xz_ut2397d8b52e1b6/p/bin:/home/pasan/.conan2/p/opens7abf84295e910/p/bin:/home/pasan/.conan2/p/zstdf09cd57eedb9b/p/bin:$PATH"
export OPENSSL_MODULES="/home/pasan/.conan2/p/opens7abf84295e910/p/lib/ossl-modules"