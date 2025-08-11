#!/usr/bin/env python3
import json, sys
j=json.load(open(sys.argv[1]))
keys=set(j.keys())
print(f"{len(keys)} strings OK.")
