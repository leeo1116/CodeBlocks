#include "Leetcode.h"


string Solution::NumToWords(int num){
    const char * const below20[] = {"One", "Two", "Three", "Four","Five","Six","Seven","Eight","Nine","Ten",
    "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
    const char * const below100[] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    if(num == 0)
        return "Zero";
    else
        return IntToStr(num, below20, below100).substr(1);
}


string Solution::IntToStr(int n, const char * const below20[], const char * const below100[]){
    if(n >= 1000000000)
        return IntToStr(n/1000000000, below20, below100)+" Billion"+IntToStr(n-(n/1000000000)*1000000000, below20, below100);
    else if(n >= 1000000)
        return IntToStr(n/1000000, below20, below100)+" Million"+IntToStr(n-(n/1000000)*1000000, below20, below100);
    else if(n >= 1000)
        return IntToStr(n/1000, below20, below100)+" Thousand"+IntToStr(n-(n/1000)*1000, below20, below100);
    else if(n >= 100)
        return IntToStr(n/100, below20, below100)+" Hundred"+IntToStr(n-(n/100)*100, below20, below100);
    else if(n >= 20)
        return string(" ")+below100[n/10-2]+IntToStr(n-(n/10)*10, below20, below100);
    else if(n >= 1)
        return string(" ")+below20[n-1];
    else
        return "";
}
