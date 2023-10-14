# Create a dictionary for movie details
movies = {
    "Movie 1": "6:00 pm, 9:00 pm",
    "Movie 2": "7:30 pm, 10:00 pm",
    "Movie 3": "8:00 pm, 11:00 pm"
}

# Display current movie details
print("Current Movies:")
for movie, timings in movies.items():
    print(movie + ":", timings)

# Add a new movie
new_movie = input("Enter the name of the new movie: ")
new_timings = input("Enter the show timings for the new movie: ")
movies[new_movie] = new_timings

# Display movies available at 9 pm
print("Movies at 9 pm:")
for movie, timings in movies.items():
    if "9:00 pm" in timings:
        print(movie)

# Remove a movie
movie_to_remove = input("Enter a movie to remove: ")
if movie_to_remove in movies:
    del movies[movie_to_remove]
    print(movie_to_remove + " removed.")
else:
    print(movie_to_remove + " not found.")

# Remove last movie
if movies:
    last_movie = list(movies.keys())[-1]
    del movies[last_movie]
    print(last_movie + " removed.")
else:
    print("No movies left.")

# Display updated movies
print("Updated Movies:")
for movie, timings in movies.items():
    print(movie + ":", timings)
