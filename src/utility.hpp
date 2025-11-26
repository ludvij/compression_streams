#include "Options.hpp"

#include <zlib.h>

namespace comp
{
auto constexpr translate_options(CompressionOptions options)
{
    struct
    {
        int level;
        int w_bits;
        int strategy;
    } t{};

    switch (options.level)
    {
    case CompressionLevel::NO_COMPRESSION:
        t.level = Z_NO_COMPRESSION;
        break;
    case CompressionLevel::DEFAULT_COMPRESSION:
        t.level = Z_DEFAULT_COMPRESSION;
        break;
    case CompressionLevel::BEST_COMPRESSION:
        t.level = Z_BEST_COMPRESSION;
    }

    switch (options.type)
    {
    case CompressionType::RAW:
        t.w_bits = -MAX_WBITS;
        break;
    case CompressionType::ZLIB:
        t.w_bits = MAX_WBITS;
        break;
    case CompressionType::GZIP:
        t.w_bits = MAX_WBITS + 16;
        break;
    case CompressionType::DETECT:
        t.w_bits = MAX_WBITS + 32;
        break;
    }

    switch (options.strategy)
    {
    case CompressionStrategy::DEFAULT:
        t.strategy = Z_DEFAULT_STRATEGY;
        break;
    case CompressionStrategy::FILTERED:
        t.strategy = Z_FILTERED;
        break;
    case CompressionStrategy::HUFFMAN_ONLY:
        t.strategy = Z_HUFFMAN_ONLY;
        break;
    case CompressionStrategy::RLE:
        t.strategy = Z_RLE;
    default:
        break;
    }

    return t;
}
} // namespace comp
