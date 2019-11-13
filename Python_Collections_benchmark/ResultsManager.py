

class ResultsManager():
    _collection_info = 'Collection name: {},number of operations: {},unit: {}'
    _columns = 'Add time,Find time,Remove time'
    _row_pattern = '{},{},{}'
    _measure_unit = "ms"

    collection_name = "None"
    number_of_operations = 0

    def save_to_csv(self,results :list, path:str):
        csv = list()
        first_row = self._collection_info.format\
            (self._collection_info, self.collection_name, self.number_of_operations, self._measure_unit)

        csv.append(first_row)
        csv.append(self._columns)

        for item in results:
            row = self._row_pattern.format(str(item.add_time), str(item.find_time), str(item.remove_time))
            csv.append(row)

        print('saving to file:' + self.collection_name)
        output = '\n'.join(csv)

        with open(path,'w') as file:
            file.write(output)

