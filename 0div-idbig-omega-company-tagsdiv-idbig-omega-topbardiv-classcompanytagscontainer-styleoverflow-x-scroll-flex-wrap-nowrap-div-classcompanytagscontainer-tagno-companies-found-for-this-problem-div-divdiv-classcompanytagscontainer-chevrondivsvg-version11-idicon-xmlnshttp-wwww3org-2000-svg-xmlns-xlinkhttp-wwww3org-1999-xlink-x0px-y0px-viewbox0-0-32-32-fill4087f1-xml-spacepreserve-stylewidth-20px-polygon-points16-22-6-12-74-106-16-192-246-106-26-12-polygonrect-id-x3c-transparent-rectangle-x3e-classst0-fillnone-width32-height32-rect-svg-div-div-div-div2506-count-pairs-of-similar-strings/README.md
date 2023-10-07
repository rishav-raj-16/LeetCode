<h2><a href="https://leetcode.com/problems/count-pairs-of-similar-strings/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag">No companies found for this problem</div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px;"><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>2506. Count Pairs Of Similar Strings</a></h2><h3>Easy</h3><hr><div><p>You are given a <strong>0-indexed</strong> string array <code>words</code>.</p>

<p>Two strings are <strong>similar</strong> if they consist of the same characters.</p>

<ul>
	<li>For example, <code>"abca"</code> and <code>"cba"</code> are similar since both consist of characters <code>'a'</code>, <code>'b'</code>, and <code>'c'</code>.</li>
	<li>However, <code>"abacba"</code> and <code>"bcfd"</code> are not similar since they do not consist of the same characters.</li>
</ul>

<p>Return <em>the number of pairs </em><code>(i, j)</code><em> such that </em><code>0 &lt;= i &lt; j &lt;= word.length - 1</code><em> and the two strings </em><code>words[i]</code><em> and </em><code>words[j]</code><em> are similar</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> words = ["aba","aabb","abcd","bac","aabc"]
<strong>Output:</strong> 2
<strong>Explanation:</strong> There are 2 pairs that satisfy the conditions:
- i = 0 and j = 1 : both words[0] and words[1] only consist of characters 'a' and 'b'. 
- i = 3 and j = 4 : both words[3] and words[4] only consist of characters 'a', 'b', and 'c'. 
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> words = ["aabb","ab","ba"]
<strong>Output:</strong> 3
<strong>Explanation:</strong> There are 3 pairs that satisfy the conditions:
- i = 0 and j = 1 : both words[0] and words[1] only consist of characters 'a' and 'b'. 
- i = 0 and j = 2 : both words[0] and words[2] only consist of characters 'a' and 'b'.
- i = 1 and j = 2 : both words[1] and words[2] only consist of characters 'a' and 'b'.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> words = ["nba","cba","dba"]
<strong>Output:</strong> 0
<strong>Explanation:</strong> Since there does not exist any pair that satisfies the conditions, we return 0.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 100</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 100</code></li>
	<li><code>words[i]</code> consist of only lowercase English letters.</li>
</ul>
</div>