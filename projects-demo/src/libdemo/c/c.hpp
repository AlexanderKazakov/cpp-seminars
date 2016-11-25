#pragma once
#include <iostream>
#include <cmath>

namespace demo {

/// Теоретически, inline -- это указание компилятору
/// подставить код функции в место её вызова.
/// Фактически, современные компиляторы сами решают,
/// подставлять функцию или нет.
/// А "inline" -- просто способ избежать ошибки 
/// "multiple definition" при компиляции
inline void foo() {
	std::cout << cos(M_PI / 2) << std::endl;
}

}
