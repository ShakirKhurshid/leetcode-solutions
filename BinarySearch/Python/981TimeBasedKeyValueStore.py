class TimeMap:

    def __init__(self):
        self.data = {}
        

    def set(self, key: str, value: str, timestamp: int) -> None:
        if key not in self.data:
            self.data[key] = self.data.get(key, [])
        self.data[key].append([value, timestamp])


    def get(self, key: str, timestamp: int) -> str:
        # Here we use binary search because time stamps are in order
        if key not in self.data:
            return ""
        right = len(self.data[key]) - 1 
        left = 0

        while left <= right:
            mid = ((right - left) // 2) + left
            if timestamp == self.data[key][mid][1]:
                return self.data[key][mid][0]
            elif timestamp > self.data[key][mid][1]:
                left = mid + 1
            elif timestamp < self.data[key][mid][1]:
                right = mid - 1

        # If timestamp not found, retrn the closest smaller timestamp
        if (right >= 0): 
            return self.data[key][right][0]
        else:
            return  ""




            #[a,1][b,2][c,3][d,4]
     
# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)