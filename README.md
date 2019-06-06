# malloc2

## API

- get_padded_size
- create_new_link
- create_new_memory_block
- search_best_fit
- detach_link

## Design

```
used => [header]--[header]--[header]--[header] ...
           |          |         |        |
datas:    tiny      large      tiny     large
```
