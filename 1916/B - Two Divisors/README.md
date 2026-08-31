<h2><a href="https://codeforces.com/contest/1916/problem/B" target="_blank" rel="noopener noreferrer">1916B — Two Divisors</a></h2>

| | |
|---|---|
| **Difficulty** | 1000 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 1916B](https://codeforces.com/contest/1916/problem/B) |

## Topics
`constructive algorithms` `math` `number theory`

---

## Problem Statement

<div class="header"><div class="title">B. Two Divisors</div><div class="time-limit"><div class="property-title">time limit per test</div>1 second</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>A certain number $$$1 \le x \le 10^9$$$ is chosen. You are given two integers $$$a$$$ and $$$b$$$, which are the two largest divisors of the number $$$x$$$. At the same time, the condition $$$1 \le a  \lt  b  \lt  x$$$ is satisfied.</p><p>For the given numbers $$$a$$$, $$$b$$$, you need to find the value of $$$x$$$.</p><p>$$$^{\dagger}$$$ The number $$$y$$$ is a divisor of the number $$$x$$$ if there is an integer $$$k$$$ such that $$$x = y \cdot k$$$.</p></div><div class="input-specification"><div class="section-title">Input</div><p>Each test consists of several test cases. The first line contains a single integer $$$t$$$ ($$$1 \le t \le 10^4$$$) — the number of test cases. Then follows the description of the test cases.</p><p>The only line of each test cases contains two integers $$$a$$$, $$$b$$$ ($$$1 \le a  \lt  b \le 10^9$$$).</p><p>It is guaranteed that $$$a$$$, $$$b$$$ are the two largest divisors for some number $$$1 \le x \le 10^9$$$.</p></div><div class="output-specification"><div class="section-title">Output</div><p>For each test case, output the number $$$x$$$, such that $$$a$$$ and $$$b$$$ are the two largest divisors of the number $$$x$$$.</p><p>If there are several answers, print any of them.</p></div><div class="sample-tests"><div class="section-title">Example</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id006119440187666708" id="id000703760340005023" class="input-output-copier">Copy</div></div><pre id="id006119440187666708"><div class="test-example-line test-example-line-even test-example-line-0">8</div><div class="test-example-line test-example-line-odd test-example-line-1">2 3</div><div class="test-example-line test-example-line-even test-example-line-2">1 2</div><div class="test-example-line test-example-line-odd test-example-line-3">3 11</div><div class="test-example-line test-example-line-even test-example-line-4">1 5</div><div class="test-example-line test-example-line-odd test-example-line-5">5 10</div><div class="test-example-line test-example-line-even test-example-line-6">4 6</div><div class="test-example-line test-example-line-odd test-example-line-7">3 9</div><div class="test-example-line test-example-line-even test-example-line-8">250000000 500000000</div></pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id009517911197547565" id="id008275005353292813" class="input-output-copier">Copy</div></div><pre id="id009517911197547565">6
4
33
25
20
12
27
1000000000
</pre></div></div></div><div class="note"><div class="section-title">Note</div><p>For the first test case, all divisors less than $$$6$$$ are equal to $$$[1, 2, 3]$$$, among them the two largest will be $$$2$$$ and $$$3$$$.</p><p>For the third test case, all divisors less than $$$33$$$ are equal to $$$[1, 3, 11]$$$, among them the two largest will be $$$3$$$ and $$$11$$$.</p><p>For the fifth test case, all divisors less than $$$20$$$ are equal to $$$[1, 2, 4, 5, 10]$$$, among them the two largest will be $$$5$$$ and $$$10$$$.</p><p>For the sixth test case, all divisors less than $$$12$$$ are equal to $$$[1, 2, 3, 4, 6]$$$, among them the two largest will be $$$4$$$ and $$$6$$$.</p></div>