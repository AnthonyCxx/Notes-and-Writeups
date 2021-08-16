# Pandas Library in Python
> Jump: <br />
> [Creating a Dataframe](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Python/Modules/Pandas.md#creating-a-dataframe-from-a-file) <br />
> [Reading Columns and Rows](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Python/Modules/Pandas.md#reading-columns-and-rows) <br />
> [Iterating over a Dataframe by Row](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Python/Modules/Pandas.md#iterating-over-a-dataframe-by-row) <br />
> [Searching and Sorting](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Python/Modules/Pandas.md#searching-and-sorting-data) <br />
> [Editing a Dataframe](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Python/Modules/Pandas.md#editing-data) <br />
> [Saving a Dataframe as a file](https://github.com/EthanC2/Notes-and-Writeups/blob/main/Python/Modules/Pandas.md#saving-data) <br />

[Pandas](https://pandas.pydata.org/) is a library for data manipulation and analysis. <br />
If you are using any persistant data from a relational database or even a NoSQL database like MongoDB, you should use pandas. 

Everything here is an excerpt from Keith Galli's [_Complete Python Pandas Data Science Tutorial!_](https://www.youtube.com/watch?v=vmEHCJofslg). [Here](https://github.com/KeithGalli/pandas/blob/master/pokemon_data.csv) is the CSV file he used.

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

## Searching and Sorting Data   

```Python
# Filtering rows based on column data
print(dataframe.loc[dataframe["Type 1"] == "Fire"])

# Filtering rows based on multiple columns' data
print(dataframe.loc[(dataframe["Type 1"] == "Grass") & (dataframe["Type 2"] == "Poison")])  # Replace '&' with '|' for 'or'

# Get dataset stats for each column (get mean, standard deviation, minimum, maximum, etc.)
print(dataframe.describe())

# Sort data by column
print(dataframe.sort_values("Name"))   # Sort by the 'Name' column

# Sort data by multiple columns
print(dataframe.sort_values(["Type 1", "HP"]))

# Sort data by column in reverse
print(dataframe.sort_values("Name", ascending=False))

# Sort data from multiple columns in reverse
print(dataframe.sort_values(["Type 1", "HP"], ascending=[1, 0]))  # ascending=[lowest -> highest (alphabetical), highest -> lowest]
```

## Editing Data

```Python
# Edit specific row/column
dataframe.iloc[0,1] = "edited data"  # Row 0, column 1 (both rows and columns are zero-indexed)

# Edit row/column by column name
dataframe.iloc[0]["Name"] = "edited data"

# Create a new column from existing columns
dataframe["Atk/Def Ratio"] = dataframe["Attack"] / dataframe["Defense"]

# Creating columns by formulating rows
datafile["Total"] = datafile.iloc[:, 4:10].sum(axis=1)  # I have no fucking clue how this works

# Dropping (deleting) columns
dataframe = dataframe.drop(columns=["Atk/Def Ratio"])
```

## Saving Data

```Python
# Saving the dataframe as a CSV file
dataframe.to_csv("filename.csv")

# Save dataframe without row numbers (indices)
dataframe.to_csv("filename.csv", index=False)

# Save dataframe with special delimiter
dataframe.to_csv("filename.csv", sep='\t')  # Separate by tabs instead of commas

# Save dataframe as Excel file
dataframe.to_excel("filename.xlsx")
```
