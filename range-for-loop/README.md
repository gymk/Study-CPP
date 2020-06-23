# Range Loop

Executes a for loop over a range

## Observing and Modifying

### Capture by Value

Elements of x is copied to y (i.e., in each iteration)

Copy construction will get invoked

```cpp
for( auto y : x )
    ...
```

### Capture by Reference (Observable and Modifiable)

Elements of x are referenced as y
That is, elements of x are observed as y and it is modifiable
This is preferred if you want to modify x

```cpp
for( auto & y : x )
    ...
```

### Capture by Reference (Observable but not Modifiable)

Elements of x are referenced as y
That is, elements of x are observed as y but it is not modifiable

```cpp
for( const auto y : x )
    ...
```

## Special Case: Proxy Iterator

Below code compilation will fail. Because std::vector template is specialized for _bool_, with the implementation that _packs_ the _bool_ to optimize space

```cpp
std::vector<bool> v = { true, true, true, true};

for(auto & y : v)
    y = !y;
```

std::vector uses __proxy iterator__ pattern. A "proxy iterator" is an iterator that, when dereferenced, does not _yield_ and ordinary _bool &_, but instead returns (by value) a _temporary object_.

To modify _std::vector\<bool\>_ in-place, you need to do __Universal Reference__ _auto&&_

```cpp
std::vector<bool> v = { true, true, true, true};

for(auto&& y : x)
    y = !y;
```

## Links

- <https://en.cppreference.com/w/cpp/language/range-for>
- <https://stackoverflow.com/questions/15927033/what-is-the-correct-way-of-using-c11s-range-based-for>
- <https://docs.microsoft.com/en-us/cpp/cpp/range-based-for-statement-cpp?view=vs-2019>
- Universal Reference
  - <https://isocpp.org/blog/2012/11/universal-references-in-c11-scott-meyers>
  - <https://stackoverflow.com/questions/13230480/what-does-auto-tell-us>
