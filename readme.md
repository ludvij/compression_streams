# Compression Streams
A stream based compression utility library, it wraps a compression algorithm in a conventient streamlike form
## Deflate implementation
In order to compress data, this implementation makes use of [zlib-ng](https://github.com/zlib-ng/zlib-ng)  
**Example 1: deflate_stream**
```c++
std::ostream out_stream = ...;
// creates a deflate stream that will write to out_stream
{
	// important to either scope this so sync is called or
	// to manually call to sync
	Lud::deflate_ostream comp_stream(out_stream);
	// writes some data
	comp_stream.write(...);
}
```

**Example 2: inflate_stream**
```c++
std::istream in_stream = ...;
// creates a deflate stream that will read from in_stream
Lud::inflate_istream decomp_stream(out_stream);
// reads some data
decomp_stream.read(...);
```

You can provide CompressionOptions to the constructor of any of those streams, the options work as a wrapper to inflateInit2 and deflateInit2 from zlib