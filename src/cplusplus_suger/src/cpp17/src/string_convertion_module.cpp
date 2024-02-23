// #include "string_convertion_module.h"

// namespace cpp17 {

// void ConvertString() {
//     const std::string str{"123456789"};
//     int value = 0;

//     const auto res = std::from_chars(str.data(), str.data() + 4, value);
//     if (res.ec == std::errc) {
//         std::cout << value << ", distance " << res.ptr -  str.data() << std::endl;
//     } else if (res.ec == std::errc::invalid_argument) {
//         std::cout << "Invalid!" << std::endl;
//     }

//     str = std::string{"12.34"};
//     double val = 0;
//     const auto format = std::chars_format::general;
//     res = std::from_chars(str.data(), str.data() + str.size(), value, format);

//     str = std::string("xxxxxxxx");
//     const int v = 1234;
//     res = std::to_chars(str.data(), str.data() + str.size(), v);
//     std::cout << str << ", filled " << res.ptr - str.data() << " characters." << std::endl;
// }

// } // namespace cpp17