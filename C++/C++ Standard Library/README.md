# The C++ Standard Library
Header files that start with _c_ belong to the [C Standard Library](https://github.com/EthanC2/Notes-and-Writeups/blob/main/C/C%20Standard%20Library/README.md).

Note: This list is not comprehensive.

| Library | Full Name | Contains |
| ------- | --------- | -------- |
| [\<iostream\>](https://en.cppreference.com/w/cpp/header/iostream) | Input/Output Stream | objects and functions for standard I/O operations ([_cin_](https://en.cppreference.com/w/cpp/io/cin) , [_cout_](https://en.cppreference.com/w/cpp/io/cout), [_cerr_](https://en.cppreference.com/w/cpp/io/cerr), [_clog_](https://en.cppreference.com/w/cpp/io/clog)) |
| [\<iomanip\>](https://en.cppreference.com/w/cpp/header/iomanip) | Input/Output Manipulation | functions and variables for manipulating I/O settings ([_setprecision_](https://en.cppreference.com/w/cpp/io/manip/setprecision), [_setw_](https://en.cppreference.com/w/cpp/io/manip/setw), [_setfill_](https://en.cppreference.com/w/cpp/io/manip/setfill), [_setbase_](https://en.cppreference.com/w/cpp/io/manip/setbase)) |
| [\<fstream\>](https://en.cppreference.com/w/cpp/header/fstream) | File Stream | datatypes and class templates for working with files ([_ifstream_](https://www.cplusplus.com/reference/fstream/ifstream/), [_ofstream_](https://www.cplusplus.com/reference/fstream/ofstream/), [_fstream_](https://www.cplusplus.com/reference/fstream/fstream/)) |
| [\<cstdio\>](https://en.cppreference.com/w/cpp/header/cstdio) | C Standard Input/Output | I/O functions from C ([_printf()_](https://en.cppreference.com/w/cpp/io/c/fprintf), [_fgets()_](https://en.cppreference.com/w/cpp/io/c/fgets), [_fgetc()_](https://en.cppreference.com/w/cpp/io/c/fgetc), [_ungetc()_](https://en.cppreference.com/w/cpp/io/c/ungetc)) |
| [\<cstdlib\>](https://en.cppreference.com/w/cpp/utility/program/exit) | C Standard Library | miscellaenous common functions from C ([_exit()_](https://en.cppreference.com/w/cpp/utility/program/exit), [_rand()_](https://en.cppreference.com/w/cpp/numeric/random/rand), [_atoi()_](https://en.cppreference.com/w/cpp/string/byte/atoi)) |
| [\<cmath\>](https://en.cppreference.com/w/cpp/header/cmath) | C Math | math-related functions ([_abs()_](https://en.cppreference.com/w/cpp/numeric/math/fabs), [_pow()_](https://en.cppreference.com/w/cpp/numeric/math/pow), [_log()_](https://en.cppreference.com/w/cpp/numeric/math/log), [_sin()_](https://en.cppreference.com/w/cpp/numeric/math/sin), [_cos()_](https://en.cppreference.com/w/cpp/numeric/math/cos), [_tan()_](https://en.cppreference.com/w/cpp/numeric/math/tan) [_ciel()_](https://en.cppreference.com/w/cpp/numeric/math/ceil), [_floor()_](https://en.cppreference.com/w/cpp/numeric/math/floor), [_round()_](https://en.cppreference.com/w/cpp/numeric/math/round)) |
| [\<\>]() |  |  |
| [\<\>]() |  |  |
| [\<\>]() |  |  |
| [\<\>]() |  |  |
| [\<\>]() |  |  |
| [\<\>]() |  |  |
| [\<\>]() |  |  |
| [\<regex\>](https://en.cppreference.com/w/cpp/header/regex) | [Regular Expressions](https://www.computerhope.com/jargon/r/regex.htm) | classes and functions for regular expressions ([_regex\_match()_](https://en.cppreference.com/w/cpp/regex/regex_match), [_regex\_search()_](https://en.cppreference.com/w/cpp/regex/regex_search), [_regex\_recplace()_](https://en.cppreference.com/w/cpp/regex/regex_replace)) |

> Note: The [_rand()_](https://en.cppreference.com/w/cpp/numeric/random/rand) function suffers from biased number distribution (see [_How much bias is introduced by the remainder technique?_](https://ericlippert.com/2013/12/16/how-much-bias-is-introduced-by-the-remainder-technique/) and [_Continuous weighted random distribution, biased toward one end_](https://gamedev.stackexchange.com/questions/12638/continuous-weighted-random-distribution-biased-toward-one-end)). 
> Use C++'s [\<random\>](https://en.cppreference.com/w/cpp/header/random) library for serious projects. <br />
>
> Reference: [All C++ Libraries](https://en.cppreference.com/w/cpp/header)
