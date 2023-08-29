#pragma once

#include <map>
enum Major {
    IT = 15,
    Chemistry = 16,
    Physics = 17,
    Biology = 18
};

static const map<Major, string> MajorNames = map<Major, string>{
    {Major::IT, "Cong nghe thong tin"},
    {Major::Chemistry, "Hoa hoc"},
    {Major::Physics, "Vat li"},
    {Major::Biology, "Sinh hoc"}
};




enum Majordate {
    othercountries = 0,
    USA = 1,

};

