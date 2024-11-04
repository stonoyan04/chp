#include "mixed_cipher.h"
#include "../lab5/columnar_transposition.h"
#include "../lab6/rle.h"

std::string MixedCipher::encode(const std::string& message, int columns) {
    ColumnarTranspositionCipher transpositionCipher;
    std::string columnarEncrypted = transpositionCipher.encrypt(message, columns);

    RunLengthEncoding rle;
    std::string rleEncoded = rle.encode(columnarEncrypted);

    return rleEncoded;
}

std::string MixedCipher::decode(const std::string& message, int columns) {
    RunLengthEncoding rle;
    std::string rleDecoded = rle.decode(message);

    ColumnarTranspositionCipher transpositionCipher;
    std::string columnarDecrypted = transpositionCipher.decrypt(rleDecoded, columns);

    return columnarDecrypted;
}