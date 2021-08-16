# Pandas Library in Python
[Pandas](https://pandas.pydata.org/) is a library for data manipulation and analysis. <br />
If you are using any persistant data from a relational database or even a NoSQL database like MongoDB, you should use pandas. 

For sake of ease, I will be using a [CSV](https://www.howtogeek.com/348960/what-is-a-csv-file-and-how-do-i-open-it/) files (comma-separated value).

## Creating a Dataframe from a File

```Python
# Reading a csv file
dataframe = pandas.read_csv("pokemon_data.csv")

# Printing data
print(dataframe)

# Print the first 10 rows
print(dataframe.head(10))

# Print the last  10 rows
print(dataframe.tail(10))
```

## Reading Columns and Rows

```Python
print(", ".join(dataframe.columns))

# Get specific row
print(dataframe.iloc[10])  # 'iloc' == 'index location'

# Get multiple specific rows
print(dataframe.iloc[0:10])

# Print a specific column
print(dataframe["Name"])

# Printing multiple specific columns
print(dataframe[["Name", "Generation", "Legendary"]])  # Notice the extra set of '[]'

# Print specific row and column
print(dataframe.iloc[0, 1])  # row 0, column 1 (both rows and columns are zero-indexed)

# Print rows X through Y
print(dataframe[0:100])

# Print rows X through Y of a specific column
print(dataframe["Name"][0:20])

# Resetting the index on new dataframes
dataframe = dataframe.reset_index()
```

## Iterating over a Dataframe by Row

```Python
# Basic iteration
for index, row in dataframe.iterrows():
    print(index, row)

# Iterating with Specific Columns
for index, row in dataframe.iterrows():
    print(index, row["Name"])
```

##

```Python

```

##

```Python

```
