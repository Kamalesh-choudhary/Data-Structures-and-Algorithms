<h2><a href="https://codeforces.com/contest/130/problem/E" target="_blank" rel="noopener noreferrer">130E — Tribonacci numbers</a></h2>

| | |
|---|---|
| **Difficulty** | 1600 |
| **Language** | Befunge |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 130E](https://codeforces.com/contest/130/problem/E) |

## Topics
`*special`

---

## Problem Statement

<div class="header"><div class="title">E. Tribonacci numbers</div><div class="time-limit"><div class="property-title">time limit per test</div>2 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>64 megabytes</div><div class="input-file input-standard" style="font-weight: bold"><div class="property-title">input</div>stdin</div><div class="output-file output-standard" style="font-weight: bold"><div class="property-title">output</div>stdout</div></div><div><p>Tribonacci numbers are a sequence of numbers, defined as follows:</p><ul><li> <span class="tex-span"><i>t</i><sub class="lower-index">0</sub> = <i>t</i><sub class="lower-index">1</sub> = 0</span>,</li><li> <span class="tex-span"><i>t</i><sub class="lower-index">2</sub> = 1</span>,</li><li> <span class="tex-span"><i>t</i><sub class="lower-index"><i>i</i></sub> = <i>t</i><sub class="lower-index"><i>i</i> - 1</sub> + <i>t</i><sub class="lower-index"><i>i</i> - 2</sub> + <i>t</i><sub class="lower-index"><i>i</i> - 3</sub></span>.</li></ul><p>You are given <span class="tex-span"><i>n</i></span>; calculate <span class="tex-span"><i>n</i></span>-th tribonacci number modulo <span class="tex-span">26</span>.</p></div><div class="input-specification"><div class="section-title">Input</div><p>The only line of input contains an integer <span class="tex-span"><i>n</i></span> (<span class="tex-span">1 ≤ <i>n</i> ≤ 1000</span>).</p></div><div class="output-specification"><div class="section-title">Output</div><p>Output <span class="tex-span"><i>n</i></span>-th tribonacci number modulo <span class="tex-span">26</span>.</p></div><div class="sample-tests"><div class="section-title">Examples</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id005657777399188897" id="id007286835997185586" class="input-output-copier">Copy</div></div><pre id="id005657777399188897">4<br></pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id009485035717883814" id="id0016790805697365085" class="input-output-copier">Copy</div></div><pre id="id009485035717883814">2<br></pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id0031895551790485055" id="id002673825179872118" class="input-output-copier">Copy</div></div><pre id="id0031895551790485055">9<br></pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id0013195737995101575" id="id005005053504038689" class="input-output-copier">Copy</div></div><pre id="id0013195737995101575">18<br></pre></div></div></div>