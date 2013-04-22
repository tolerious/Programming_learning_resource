echo on
word_transform data\trans-map data\trans-text
query data\Alice_story < data\query_in
3ed_query data\Alice_story < data\query_in

word_count < word_count.cc
erasemap < erasemap.cc
setexclusion data\remove_words < README

multimap
