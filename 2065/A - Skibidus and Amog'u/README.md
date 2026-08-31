<h2><a href="https://codeforces.com/contest/2065/problem/A" target="_blank" rel="noopener noreferrer">2065A — Skibidus and Amog'u</a></h2>

| | |
|---|---|
| **Difficulty** | 800 |
| **Language** | C++17 (GCC 7-32) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 2065A](https://codeforces.com/contest/2065/problem/A) |

## Topics
`brute force` `constructive algorithms` `greedy` `implementation` `strings`

---

## Problem Statement

<div class="header"><div class="title">A. Skibidus and Amog'u</div><div class="time-limit"><div class="property-title">time limit per test</div>1 second</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>Skibidus lands on a foreign planet, where the local Amog tribe speaks the Amog'u language. In <span class="tex-font-style-it">Amog'u</span>, there are two forms of nouns, which are <span class="tex-font-style-it">singular</span> and <span class="tex-font-style-it">plural</span>.</p><p>Given that the root of the noun is transcribed as $$$S$$$, the two forms are transcribed as:</p><ul> <li> Singular: $$$S$$$ $$$+$$$ "<span class="tex-font-style-tt">us</span>" </li><li> Plural: $$$S$$$ $$$+$$$ "<span class="tex-font-style-tt">i</span>" </li></ul><p>Here, $$$+$$$ denotes <a href="https://en.wikipedia.org/wiki/Concatenation">string concatenation</a>. For example, <span class="tex-font-style-tt">abc</span> $$$+$$$ <span class="tex-font-style-tt">def</span> $$$=$$$ <span class="tex-font-style-tt">abcdef</span>.</p><p>For example, when $$$S$$$ is transcribed as "<span class="tex-font-style-tt">amog</span>", then the singular form is transcribed as "<span class="tex-font-style-tt">amogus</span>", and the plural form is transcribed as "<span class="tex-font-style-tt">amogi</span>". Do note that <span class="tex-font-style-it">Amog'u</span> nouns can have an <span class="tex-font-style-bf">empty</span> root — in specific, "<span class="tex-font-style-tt">us</span>" is the singular form of "<span class="tex-font-style-tt">i</span>" (which, on an unrelated note, means "imposter" and "imposters" respectively).</p><p>Given a transcribed <span class="tex-font-style-it">Amog'u</span> noun in singular form, please convert it to the transcription of the corresponding plural noun.</p></div><div class="input-specification"><div class="section-title">Input</div><p>Each test contains multiple test cases. The first line contains the number of test cases $$$t$$$ ($$$1 \le t \le 100$$$). The description of the test cases follows. </p><p>The only line of each test case contains a string $$$W$$$, which is a transcribed <span class="tex-font-style-it">Amog'u</span> noun in <span class="tex-font-style-it">singular</span> form. It is guaranteed that $$$W$$$ consists of only lowercase English letters, has a length of at most $$$10$$$, and ends with "<span class="tex-font-style-tt">us</span>".</p></div><div class="output-specification"><div class="section-title">Output</div><p>For each test case, output the transcription of the corresponding plural noun on a separate line.</p></div><div class="sample-tests"><div class="section-title">Example</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id005490784997153857" id="id0028920685478918073" class="input-output-copier">Copy</div></div><pre id="id005490784997153857"><div class="test-example-line test-example-line-even test-example-line-0">9</div><div class="test-example-line test-example-line-odd test-example-line-1">us</div><div class="test-example-line test-example-line-even test-example-line-2">sus</div><div class="test-example-line test-example-line-odd test-example-line-3">fungus</div><div class="test-example-line test-example-line-even test-example-line-4">cactus</div><div class="test-example-line test-example-line-odd test-example-line-5">sussus</div><div class="test-example-line test-example-line-even test-example-line-6">amogus</div><div class="test-example-line test-example-line-odd test-example-line-7">chungus</div><div class="test-example-line test-example-line-even test-example-line-8">ntarsus</div><div class="test-example-line test-example-line-odd test-example-line-9">skibidus</div></pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id00038520471739801665" id="id008144461170352848" class="input-output-copier">Copy</div></div><pre id="id00038520471739801665">i
si
fungi
cacti
sussi
amogi
chungi
ntarsi
skibidi
</pre></div></div></div>