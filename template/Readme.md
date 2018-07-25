

## Common:
    *) Template won't work for every type
        *) if type that is passed do not have copy constructor (say std::unique_str or std::unique_lock), then template may not work as expected
        *) need more handling who uses that template
        *) std::vector<bool> is not a container. If T is std::vector<bool> it won't work for any modification (capture by reference). Because of proxy iterator given by std::vector<bool>

## Template Function
    - inside template how args are handled? pass by value?

## Template Argument Detection
    *) refer size_of.cpp

## Need to anaylyse more how this works

    tempplate<typename T>
    struct foo {
        using type = t;
    };
    template<>
    struct foo<bool> {
        using type = char;
    };

    template<typename t, typename... p>
    using fixed_vector = std::vector<typename foo<t>::type, p...>;

    [Link](https://stackoverflow.com/questions/8399417/why-vectorboolreference-doesnt-return-reference-to-bool)