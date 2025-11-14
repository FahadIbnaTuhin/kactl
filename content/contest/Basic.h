/**
 * Author: Mattias de Zalenski, Fredrik Niemelä, Per Austrin, Simon Lindholm
 * Date: 2002-09-26
 * Source: Max Bennedich
 * Description: Computes $\displaystyle \binom{k_1 + \dots + k_n}{k_1, k_2, \dots, k_n} = \frac{(\sum k_i)!}{k_1!k_2!...k_n!}$.
 * Status: Tested on kattis:lexicography
 */
#pragma once

// Sublime Setup Windows:
https://www.youtube.com/watch?v=9JrRbVRhEf0
Download link: https://www.sublimetext.com/download_thanks?target=win-x64
{
    "cmd": ["g++.exe", "-std=c++17", "${file}",
            "-o", "${file_base_name}.exe",
            "&&", "${file_base_name}.exe<inputf.in>outputf.out"],
    "shell":true,
    "working_dir":"$file_path",
    "selector":"source.cpp"
}

CP.sublime-build

“C:\MinGW\lib\gcc\mingw32\6.3.0\include\c++\mingw32\bits”
g++ stdc++.h -std=c++17

// Sublime Setup Linux:
c++17.sublime-build
{
"cmd" : ["g++ -std=c++17 $file_name -o $file_base_name && timeout 4s ./$file_base_name<inputf.in>outputf.in"], 
"selector" : "source.c",
"shell": true,
"working_dir" : "$file_path"
}

// Preference
{
	"save_on_focus_lost": true, 

	"ignored_packages":
	[
		"Vintage",
	],
	"index_files": true,

	"hot_exit": true,
	"remember_open_files": true,

	"enabled": true,
    "save_on_modified": true,
    "debounce_delay": 1000
}

// Bit Manipulation Templation
inline bool check_kth_bit(ll x, ll k) { return (x & (1ULL << k)) != 0; }
inline ll set_kth_bit(ll x, ll k) { return x | (1ULL << k); }
inline ll unset_kth_bit(ll x, ll k) { return x & ~(1ULL << k); }
inline ll toggle_kth_bit(ll x, ll k) { return x ^ (1ULL << k); }
inline bool check_power_of_2(ll x) { return x > 0 && (x & (x - 1)) == 0; }
inline int countSetBits(ll x) { return __builtin_popcountll(x); }
inline ll lowestSetBitPos(ll x) { return x ? __builtin_ctzll(x) : -1; }
inline ll MSB(ll x) { return x > 0 ? 63 - __builtin_clzll(x) : -1; }

