# Timestamp_BOF

Cobalt Strike Beacon Object File (BOF) that changes the time and date of a file. This can be useful when you need to drop files to disk for persistence and want to blend in with other files in the same folder. 

## Compile

```
git clone https://github.com/carlnykvist/Timestamp_BOF
cd Timestamp_BOF
make
```

## Usage

Load the provided aggressor script and run the command:

```
timestamp C:\Users\joker\Downloads\phase4.txt "2007-09-02 16:05:01"
```

![](/images/timestamp.png)


### Credits / References
##### Cobalt Strike - Beacon Object Files
+ https://www.cobaltstrike.com/help-beacon-object-files
##### BOF Code References
###### trustedsec/CS-Situational-Awareness-BOF
+ https://github.com/trustedsec/CS-Situational-Awareness-BOF
