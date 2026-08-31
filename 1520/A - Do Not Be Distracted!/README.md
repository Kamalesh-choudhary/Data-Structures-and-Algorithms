<h2><a href="https://codeforces.com/contest/1520/problem/A" target="_blank" rel="noopener noreferrer">1520A — Do Not Be Distracted!</a></h2>

| | |
|---|---|
| **Difficulty** | 800 |
| **Language** | C++17 (GCC 7-32) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 1520A](https://codeforces.com/contest/1520/problem/A) |

## Topics
`brute force` `implementation`

---

## Problem Statement

<div class="header"><div class="title">A. Do Not Be Distracted!</div><div class="time-limit"><div class="property-title">time limit per test</div>1 second</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>Polycarp has <span class="MathJax_Preview" style="color: inherit;"><span class="MJXp-math" id="MJXp-Span-1"><span class="MJXp-mn" id="MJXp-Span-2">26</span></span></span>$26$ tasks. Each task is designated by a capital letter of the Latin alphabet.</p><p>The teacher asked Polycarp to solve tasks in the following way: if Polycarp began to solve some task, then he must solve it to the end, without being distracted by another task. After switching to another task, Polycarp cannot return to the previous task.</p><p>Polycarp can only solve one task during the day. Every day he wrote down what task he solved. Now the teacher wants to know if Polycarp followed his advice.</p><p>For example, if Polycarp solved tasks in the following order: "<span class="tex-font-style-tt">DDBBCCCBBEZ</span>", then the teacher will see that on the third day Polycarp began to solve the task '<span class="tex-font-style-tt">B</span>', then on the fifth day he got distracted and began to solve the task '<span class="tex-font-style-tt">C</span>', on the eighth day Polycarp returned to the task '<span class="tex-font-style-tt">B</span>'. Other examples of when the teacher is suspicious: "<span class="tex-font-style-tt">BAB</span>", "<span class="tex-font-style-tt">AABBCCDDEEBZZ</span>" and "<span class="tex-font-style-tt">AAAAZAAAAA</span>".</p><p>If Polycarp solved the tasks as follows: "<span class="tex-font-style-tt">FFGZZZY</span>", then the teacher cannot have any suspicions. Please note that Polycarp is not obligated to solve all tasks. Other examples of when the teacher doesn't have any suspicious: "<span class="tex-font-style-tt">BA</span>", "<span class="tex-font-style-tt">AFFFCC</span>" and "<span class="tex-font-style-tt">YYYYY</span>".</p><p>Help Polycarp find out if his teacher might be suspicious.</p></div><div class="input-specification"><div class="section-title">Input</div><p>The first line contains an integer <span class="MathJax_Preview" style="color: inherit;"><span class="MJXp-math" id="MJXp-Span-3"><span class="MJXp-mi MJXp-italic" id="MJXp-Span-4">t</span></span></span>$t$ (<span class="MathJax_Preview" style="color: inherit;"><span class="MJXp-math" id="MJXp-Span-5"><span class="MJXp-mn" id="MJXp-Span-6">1</span><span class="MJXp-mo" id="MJXp-Span-7" style="margin-left: 0.333em; margin-right: 0.333em;">≤</span><span class="MJXp-mi MJXp-italic" id="MJXp-Span-8">t</span><span class="MJXp-mo" id="MJXp-Span-9" style="margin-left: 0.333em; margin-right: 0.333em;">≤</span><span class="MJXp-mn" id="MJXp-Span-10">1000</span></span></span>$1 \le t \le 1000$). Then <span class="MathJax_Preview" style="color: inherit;"><span class="MJXp-math" id="MJXp-Span-11"><span class="MJXp-mi MJXp-italic" id="MJXp-Span-12">t</span></span></span>$t$ test cases follow.</p><p>The first line of each test case contains one integer <span class="MathJax_Preview" style="color: inherit;"><span class="MJXp-math" id="MJXp-Span-13"><span class="MJXp-mi MJXp-italic" id="MJXp-Span-14">n</span></span></span>$n$ (<span class="MathJax_Preview" style="color: inherit;"><span class="MJXp-math" id="MJXp-Span-15"><span class="MJXp-mn" id="MJXp-Span-16">1</span><span class="MJXp-mo" id="MJXp-Span-17" style="margin-left: 0.333em; margin-right: 0.333em;">≤</span><span class="MJXp-mi MJXp-italic" id="MJXp-Span-18">n</span><span class="MJXp-mo" id="MJXp-Span-19" style="margin-left: 0.333em; margin-right: 0.333em;">≤</span><span class="MJXp-mn" id="MJXp-Span-20">50</span></span></span>$1 \le n \le 50$) — the number of days during which Polycarp solved tasks.</p><p>The second line contains a string of length <span class="MathJax_Preview" style="color: inherit;"><span class="MJXp-math" id="MJXp-Span-21"><span class="MJXp-mi MJXp-italic" id="MJXp-Span-22">n</span></span></span>$n$, consisting of uppercase Latin letters, which is the order in which Polycarp solved the tasks.</p></div><div class="output-specification"><div class="section-title">Output</div><p>For each test case output: </p><ul> <li> "<span class="tex-font-style-tt">YES</span>", if the teacher <span class="tex-font-style-bf">cannot be suspicious</span>; </li><li> "<span class="tex-font-style-tt">NO</span>", otherwise. </li></ul><p>You may print every letter in any case you want (so, for example, the strings <span class="tex-font-style-tt">yEs</span>, <span class="tex-font-style-tt">yes</span>, <span class="tex-font-style-tt">Yes</span> and <span class="tex-font-style-tt">YES</span> are all recognized as positive answer).</p></div><div class="sample-tests"><div class="section-title">Example</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id00024442061349387645" id="id005637340804868906" class="input-output-copier">Copy</div></div><pre id="id00024442061349387645">5
3
ABA
11
DDBBCCCBBEZ
7
FFGZZZY
1
Z
2
AB
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id004175039022577889" id="id006373479610945474" class="input-output-copier">Copy</div></div><pre id="id004175039022577889">NO
NO
YES
YES
YES
</pre></div></div></div>