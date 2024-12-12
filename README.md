# My Garbage Collector in C

Simple garbage collector in C to manage dynamic memory allocations.

## How to Use

### Compile my_garbage_collector.a

```bash
gcl https://github.com/MathysCogne/my_garbage_collector_c && cd my_garbage_collector_c

make
```

### Initialization

Initialize the garbage collector:
```c
t_gc	*gc;
gc = gc_init();
```

</br>

### Add to the garbage collector

```c
char *str = strdup("Hello, 42 !");
if (!str)
{
	gc_clean(gc);
	return (1);
}
gc_add(gc, (void *)str);
```

</br>

### Clean

Remove and free one:
```c
gc_remove_one(gc, (void *)str);
```

</br>

Remove and free all:
```c
gc_clean(gc);
```

</br>

### Debug

Print all allocations in the garbage collector:
```c
gc_print_debug(gc);
```
