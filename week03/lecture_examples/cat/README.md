This example demonstrates the use of the `istream_iterator` and `ostream_iterator` types 
for reading and writing standard output. Please note that those are using `operator>>` and `operator<<` 
respectively for reading and writing values, so that contiguous whitespace gets compressed to a single blank on 
output.

*CAUTION* Do not run this within the Cevelop Console on non-Windows operating systems, because
Eclipse had a bug with the EOF (Ctrl-D) handling in its console.