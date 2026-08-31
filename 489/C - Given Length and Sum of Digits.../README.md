<h2><a href="https://codeforces.com/contest/489/problem/C" target="_blank" rel="noopener noreferrer">489C — Given Length and Sum of Digits...</a></h2>

| | |
|---|---|
| **Difficulty** | 1400 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 489C](https://codeforces.com/contest/489/problem/C) |

## Topics
`dp` `greedy` `implementation`

---

## Problem Statement

<div class="header"><div class="title">C. Given Length and Sum of Digits...</div><div class="time-limit"><div class="property-title">time limit per test</div>1 second</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard" style="font-weight: bold"><div class="property-title">input</div>stdin</div><div class="output-file output-standard" style="font-weight: bold"><div class="property-title">output</div>stdout</div></div><div><p>You have a positive integer <span class="tex-span"><i>m</i></span> and a non-negative integer <span class="tex-span"><i>s</i></span>. Your task is to find the smallest and the largest of the numbers that have length <span class="tex-span"><i>m</i></span> and sum of digits <span class="tex-span"><i>s</i></span>. The required numbers should be non-negative integers written in the decimal base without leading zeroes.</p></div><div class="input-specification"><div class="section-title">Input</div><p>The single line of the input contains a pair of integers <span class="tex-span"><i>m</i></span>, <span class="tex-span"><i>s</i></span> (<span class="tex-span">1 ≤ <i>m</i> ≤ 100, 0 ≤ <i>s</i> ≤ 900</span>) — the length and the sum of the digits of the required numbers.</p></div><div class="output-specification"><div class="section-title">Output</div><p>In the output print the pair of the required non-negative integer numbers — first the minimum possible number, then — the maximum possible number. If no numbers satisfying conditions required exist, print the pair of numbers "<span class="tex-font-style-tt">-1 -1</span>" (without the quotes).</p></div><div class="sample-tests"><div class="section-title">Examples</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id0022831481938154274" id="id008167286942704924" class="input-output-copier">Copy</div></div><pre id="id0022831481938154274">2 15<br></pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id00054113610682736346" id="id006277107584060463" class="input-output-copier">Copy</div></div><pre id="id00054113610682736346">69 96<br></pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id009487731096718343" id="id007992450280161665" class="input-output-copier">Copy</div></div><pre id="id009487731096718343">3 0<br></pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id006459910234130594" id="id0008248278389623487" class="input-output-copier">Copy</div></div><pre id="id006459910234130594">-1 -1<br></pre></div></div></div>