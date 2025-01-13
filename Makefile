LDLIBS = -lm -lpthread

program: program.c
    $(CC) $(CFLAGS) $^ $(LDLIBS) -o $@

echo1: dep1 dep2 dep3 dep4
    @echo "All dependencies: $^"
    @echo "Dependencies after the first: $(wordlist 2,$(words $^),$^)"

echo2: dep1 dep2 dep3 dep4
    @echo "All dependencies: $^"
    @echo "All dependencies except the first: $(filter-out $<,$^)"