class AdjacencyList:
    def __init__(self):
        self.graph = {}

    def add_student(self, student_name):
        self.graph[student_name] = []

    def add_friend(self, student_name, friend_name):
        if student_name in self.graph:
            self.graph[student_name].append(friend_name)
        else:
            print(f"Mahasiswa {student_name} belum terdaftar.")

    def remove_student(self, student_name):
        if student_name in self.graph:
            del self.graph[student_name]
            for friends in self.graph.values():
                if student_name in friends:
                    friends.remove(student_name)
        else:
            print(f"Mahasiswa {student_name} tidak ditemukan.")

    def common_friends(self, student1, student2):
        if student1 in self.graph and student2 in self.graph:
            common = set(self.graph[student1]) & set(self.graph[student2])
            return list(common)
        else:
            return []

    def get_friends(self, student_name):
        if student_name in self.graph:
            return self.graph[student_name]
        else:
            return []

# Contoh penggunaan
adj_list = AdjacencyList()
adj_list.add_student("Alice")
adj_list.add_student("Bob")
adj_list.add_student("Charlie")

adj_list.add_friend("Alice", "Bob")
adj_list.add_friend("Alice", "Charlie")

print("Teman Alice:", adj_list.get_friends("Alice"))
print("Teman Bob:", adj_list.get_friends("Bob"))

print("Teman yang sama antara Alice dan Bob:", adj_list.common_friends("Alice", "Bob"))

adj_list.remove_student("Charlie")
print("Teman Alice setelah menghapus Charlie:", adj_list.get_friends("Alice"))
