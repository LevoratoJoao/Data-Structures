from hashTable import HashTable

hash = HashTable(10)

hash.put(2, "Joao")
hash.put(8, "Maria")
hash.put(6, "Carla")
hash.put(19, "Pedro")
hash.put(6, "Gustav")
hash.put(5, "Angelica")
hash.put(10, "Tatiana")
hash.put(20, "liver")
hash.put(50, "Leticia")

print("Hash table:")
hash.show()
hash.get(10)
hash.remove(19)
print("Hash table:")
hash.show()
hash.get(19)

hash.free()