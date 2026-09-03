<h2><a href="https://codeforces.com/contest/1272/problem/C" target="_blank" rel="noopener noreferrer">1272C — Yet Another Broken Keyboard</a></h2>

| | |
|---|---|
| **Difficulty** | 1200 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 1272C](https://codeforces.com/contest/1272/problem/C) |

## Topics
`combinatorics` `dp` `implementation`

---

## Problem Statement

<div class="header"><div class="title">C. Yet Another Broken Keyboard</div><div class="time-limit"><div class="property-title">time limit per test</div>2 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>Recently, Norge found a string $$$s = s_1 s_2 \ldots s_n$$$ consisting of $$$n$$$ lowercase Latin letters. As an exercise to improve his typing speed, he decided to type all substrings of the string $$$s$$$. Yes, all $$$\frac{n (n + 1)}{2}$$$ of them!</p><p>A substring of $$$s$$$ is a non-empty string $$$x = s[a \ldots b] = s_{a} s_{a + 1} \ldots s_{b}$$$ ($$$1 \leq a \leq b \leq n$$$). For example, "<span class="tex-font-style-tt">auto</span>" and "<span class="tex-font-style-tt">ton</span>" are substrings of "<span class="tex-font-style-tt">automaton</span>".</p><p>Shortly after the start of the exercise, Norge realized that his keyboard was broken, namely, he could use only $$$k$$$ Latin letters $$$c_1, c_2, \ldots, c_k$$$ out of $$$26$$$.</p><p>After that, Norge became interested in how many substrings of the string $$$s$$$ he could still type using his broken keyboard. Help him to find this number.</p></div><div class="input-specification"><div class="section-title">Input</div><p>The first line contains two space-separated integers $$$n$$$ and $$$k$$$ ($$$1 \leq n \leq 2 \cdot 10^5$$$, $$$1 \leq k \leq 26$$$) — the length of the string $$$s$$$ and the number of Latin letters still available on the keyboard.</p><p>The second line contains the string $$$s$$$ consisting of exactly $$$n$$$ lowercase Latin letters.</p><p>The third line contains $$$k$$$ space-separated distinct lowercase Latin letters $$$c_1, c_2, \ldots, c_k$$$ — the letters still available on the keyboard.</p></div><div class="output-specification"><div class="section-title">Output</div><p>Print a single number — the number of substrings of $$$s$$$ that can be typed using only available letters $$$c_1, c_2, \ldots, c_k$$$.</p></div><div class="sample-tests"><div class="section-title">Examples</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id0033566285134236173" id="id003766720114142367" class="input-output-copier">Copy</div></div><pre id="id0033566285134236173">7 2
abacaba
a b
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id0021479939599501663" id="id005443689444252249" class="input-output-copier">Copy</div></div><pre id="id0021479939599501663">12
</pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id002612106796800169" id="id005259557184353578" class="input-output-copier">Copy</div></div><pre id="id002612106796800169">10 3
sadfaasdda
f a d
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id002624910582354527" id="id003804778706159099" class="input-output-copier">Copy</div></div><pre id="id002624910582354527">21
</pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id007734624266192968" id="id0010558542653438163" class="input-output-copier">Copy</div></div><pre id="id007734624266192968">7 1
aaaaaaa
b
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id004981073479358914" id="id006467438611748638" class="input-output-copier">Copy</div></div><pre id="id004981073479358914">0
</pre></div></div></div><div class="note"><div class="section-title">Note</div><p>In the first example Norge can print substrings $$$s[1\ldots2]$$$, $$$s[2\ldots3]$$$, $$$s[1\ldots3]$$$, $$$s[1\ldots1]$$$, $$$s[2\ldots2]$$$, $$$s[3\ldots3]$$$, $$$s[5\ldots6]$$$, $$$s[6\ldots7]$$$, $$$s[5\ldots7]$$$, $$$s[5\ldots5]$$$, $$$s[6\ldots6]$$$, $$$s[7\ldots7]$$$.</p></div>