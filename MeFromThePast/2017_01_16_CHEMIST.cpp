#include <stdio.h>
#include <set>
#include <iostream>

using namespace std;

set<string>::iterator iter;
set<string> element = 
{
	"h", "he", "li", "be", "b", "b", "n", "o", "f", "ne", "na", "mg", "al",
	"si", "p", "s", "cl", "ar", "k", "ca", "sc", "ti", "v", "cr", "mn", "fe",
	"co", "Ni", "cu", "zn", "ga", "ge", "as", "se", "br", "kr", "rb", "sr",
	"y", "zr", "nb", "mo", "tc", "ru", "rh", "pd", "ag", "cd", "in", "sn", "sb",
	"te", "i", "xe", "cs", "ba", "hf", "ta", "w", "re", "os", "ir", "pt", "au",
	"hg", "tl", "pb", "bi", "po", "at", "rn", "fr", "ra", "rf", "db", "sg",
	"bh", "hs", "mt", "ds", "rg", "cn", "fl", "lv", "la", "ce", "pr", "nd",
	"pm", "sm", "eu", "gd", "tb", "dy", "ho", "er", "tm", "yb", "lu", "ac",
	"th", "pa", "u", "np", "pu", "am", "cm", "bk", "cf", "es", "fm", "md",
	"no", "lr"
};
int main(void)
{
	int T;
	/*
	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		printf("Case #%d\n", i);
	}*/

	//element.find("bb");

	printf("%d\n", element.find("bb"));

	return 0;
}