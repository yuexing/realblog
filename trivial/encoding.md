# Encoding

- ASCII-7 is able to encode English letters

- ASCII-8: 0-127 is the same as ASCII-7, above 128 is different among locations. That's called code-page

- Unicode: tries to solve the code-page problem. A charactor is mapped to code points.
  - Encoding: UTF-8 (variable length), UTF-16 (use FFFE to help recognize endian), UCS-2(16bit, 8bit a char), UCS-16(16bit a char)
  - Specials: 
    - U+FFFD: replacement charactor for unknown or unrepresentable character
    - U+FFFE, U+FFFF: not a charactor, for recognizing the schema


# Collation

- VS. classification: classification is to logically classify, which collation is to sort

- just consider how to sort Chinese Charactors?