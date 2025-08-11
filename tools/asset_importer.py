#!/usr/bin/env python3
"""
Convert glTF models to a minimal engine-ready JSON mesh format.
This tool only packs positions + UVs to keep runtime simple.
"""
import json, sys
from pathlib import Path

def run(src, dst):
    # Minimal passthrough example (expects already-simple meshes)
    data = Path(src).read_text()
    Path(dst).write_text(json.dumps({"source":"gltf","payload":data[:128]}))

if __name__=="__main__":
    if len(sys.argv)<3:
        print("usage: asset_importer.py in.gltf out.json"); sys.exit(1)
    run(sys.argv[1], sys.argv[2])
