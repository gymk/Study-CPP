# Delegating Constructors

- From C++11, we can forward one constructor to another
- This is particularly useful when we need to have thread-safe copy/move constructors

**Syntax:** `constructor(...) : constructor(...)`

```cpp
Guess::GUess()
{
  language_str = DEFAULT_LANGUAGE;
  country_str = DEFAULT_COUNTRY;
  encoding_str = DEFAULT_ENCODING;
}
Guess::Guess(const char * guess_str) : Guess ()
{
  ...
}
```

## Links

- [1]<https://hownot2code.com/2016/06/09/how-to-properly-call-one-constructor-from-another/>
- [2]<https://docs.microsoft.com/en-us/cpp/cpp/delegating-constructors?view=vs-2019>
