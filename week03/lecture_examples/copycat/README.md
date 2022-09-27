This example demonstrates the use of the `istreambuf_iterator` and `ostream_iterator` types 
for reading and writing standard output. Since `istreambuf_iterator` uses the `get(char)` member function
of `std::istream` it will read all characters and not skip whitespace on input.
