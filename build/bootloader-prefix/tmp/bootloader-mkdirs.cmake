# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/sulof/esp/v5.3.1/esp-idf/components/bootloader/subproject"
  "H:/ProgrammingHome/IoT/wifi_led_matrix/build/bootloader"
  "H:/ProgrammingHome/IoT/wifi_led_matrix/build/bootloader-prefix"
  "H:/ProgrammingHome/IoT/wifi_led_matrix/build/bootloader-prefix/tmp"
  "H:/ProgrammingHome/IoT/wifi_led_matrix/build/bootloader-prefix/src/bootloader-stamp"
  "H:/ProgrammingHome/IoT/wifi_led_matrix/build/bootloader-prefix/src"
  "H:/ProgrammingHome/IoT/wifi_led_matrix/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "H:/ProgrammingHome/IoT/wifi_led_matrix/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "H:/ProgrammingHome/IoT/wifi_led_matrix/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
