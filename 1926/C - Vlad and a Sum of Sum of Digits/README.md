<h2><a href="https://codeforces.com/contest/1926/problem/C" target="_blank" rel="noopener noreferrer">1926C — Vlad and a Sum of Sum of Digits</a></h2>

| | |
|---|---|
| **Difficulty** | 1200 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 1926C](https://codeforces.com/contest/1926/problem/C) |

## Topics
`dp` `implementation`

---

## Problem Statement

<div class="header"><div class="title">C. Vlad and a Sum of Sum of Digits</div><div class="time-limit"><div class="property-title">time limit per test</div>0.5 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p><span class="tex-font-style-it"><span class="tex-font-style-bf">Please note that the time limit for this problem is only 0.5 seconds per test.</span></span></p><p>Vladislav wrote the integers from $$$1$$$ to $$$n$$$, inclusive, on the board. Then he replaced each integer with the sum of its digits.</p><p>What is the sum of the numbers on the board now?</p><p>For example, if $$$n=12$$$ then initially the numbers on the board are: $$$$$$1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12.$$$$$$ Then after the replacement, the numbers become: $$$$$$1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3.$$$$$$ The sum of these numbers is $$$1+2+3+4+5+6+7+8+9+1+2+3=51$$$. Thus, for $$$n=12$$$ the answer is $$$51$$$.</p></div><div class="input-specification"><div class="section-title">Input</div><p>The first line contains an integer $$$t$$$ ($$$1 \leq t \leq 10^4$$$) — the number of test cases.</p><p>The only line of each test case contains a single integer $$$n$$$ ($$$1 \leq n \leq 2 \cdot 10^5$$$) — the largest number Vladislav writes.</p></div><div class="output-specification"><div class="section-title">Output</div><p>For each test case, output a single integer — the sum of the numbers at the end of the process.</p></div><div class="sample-tests"><div class="section-title">Example</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id003587462500291161" id="id009428933776012529" class="input-output-copier">Copy</div></div><pre id="id003587462500291161"><div class="test-example-line test-example-line-even test-example-line-0">7</div><div class="test-example-line test-example-line-odd test-example-line-1">12</div><div class="test-example-line test-example-line-even test-example-line-2">1</div><div class="test-example-line test-example-line-odd test-example-line-3">2</div><div class="test-example-line test-example-line-even test-example-line-4">3</div><div class="test-example-line test-example-line-odd test-example-line-5">1434</div><div class="test-example-line test-example-line-even test-example-line-6">2024</div><div class="test-example-line test-example-line-odd test-example-line-7">200000</div></pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id00028605511463833277" id="id0015657912774216587" class="input-output-copier">Copy</div></div><pre id="id00028605511463833277">51
1
3
6
18465
28170
4600002
</pre></div></div></div>