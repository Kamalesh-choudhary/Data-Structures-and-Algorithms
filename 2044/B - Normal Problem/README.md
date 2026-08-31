<h2><a href="https://codeforces.com/contest/2044/problem/B" target="_blank" rel="noopener noreferrer">2044B — Normal Problem</a></h2>

| | |
|---|---|
| **Difficulty** | 800 |
| **Language** | C++20 (GCC 13-64) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 2044B](https://codeforces.com/contest/2044/problem/B) |

## Topics
`implementation` `strings`

---

## Problem Statement

<div class="header"><div class="title">B. Normal Problem</div><div class="time-limit"><div class="property-title">time limit per test</div>1 second</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>A string consisting of only characters 'p', 'q', and 'w' is painted on a glass window of a store. Ship walks past the store, standing directly in front of the glass window, and observes string $$$a$$$. Ship then heads inside the store, looks directly at the same glass window, and observes string $$$b$$$.</p><p>Ship gives you string $$$a$$$. Your job is to find and output $$$b$$$.</p></div><div class="input-specification"><div class="section-title">Input</div><p>The first line contains an integer $$$t$$$ ($$$1 \leq t \leq 100$$$) — the number of test cases.</p><p>The only line of each test case contains a string $$$a$$$ ($$$1 \leq |a| \leq 100$$$) — the string Ship observes from outside the store. It is guaranteed that $$$a$$$ only contains characters 'p', 'q', and 'w'.</p></div><div class="output-specification"><div class="section-title">Output</div><p>For each test case, output string $$$b$$$, the string Ship observes from inside the store, on a new line.</p></div><div class="sample-tests"><div class="section-title">Example</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id008275472850689932" id="id002242723883301736" class="input-output-copier">Copy</div></div><pre id="id008275472850689932"><div class="test-example-line test-example-line-even test-example-line-0">5</div><div class="test-example-line test-example-line-odd test-example-line-1">qwq</div><div class="test-example-line test-example-line-even test-example-line-2">ppppp</div><div class="test-example-line test-example-line-odd test-example-line-3">pppwwwqqq</div><div class="test-example-line test-example-line-even test-example-line-4">wqpqwpqwwqp</div><div class="test-example-line test-example-line-odd test-example-line-5">pqpqpqpq</div></pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id00049586615449685234" id="id004840252046944269" class="input-output-copier">Copy</div></div><pre id="id00049586615449685234">pwp
qqqqq
pppwwwqqq
qpwwpqwpqpw
pqpqpqpq
</pre></div></div></div>