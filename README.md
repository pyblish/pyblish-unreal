# Unreal Python plugin template
A Pyblish plugin for Unreal. That adds a tool button to launch Pyblish in Unreal  
<img src="https://github.com/pyblish/pyblish-unreal/assets/3758308/1c18bc63-45c7-4a2c-8b65-7221cb391d76" data-canonical-src="https://github.com/pyblish/pyblish-unreal/assets/3758308/1c18bc63-45c7-4a2c-8b65-7221cb391d76" width="300"/>

## install
- copy the whole `Pyblish` folder to your plugins path. e.g. `C:\Users\hanne\Documents\Unreal Projects\MyProject\Plugins`
- install the dependencies from `requirements.txt` 
```
pip install -r requirements.txt --target "C:\Users\hanne\Documents\Unreal Projects\MyProject\Content\Python\Lib\site-packages"
```
or 
```
pip install pyblish-lite unreal-qt --target "C:\Users\hanne\Documents\Unreal Projects\MyProject\Content\Python\Lib\site-packages"
```

- open the plugin manager
- Enable the `Pyblish` Unreal plugin  
<img src="https://github.com/pyblish/pyblish-unreal/assets/3758308/50158cbd-ea82-4759-95e8-cda955edfd71" data-canonical-src="https://github.com/pyblish/pyblish-unreal/assets/3758308/50158cbd-ea82-4759-95e8-cda955edfd71" width="500"/>

- restart Unreal
- launch from the tool button (circled)

<!-- TODO add requirements, unreal version, qt, ... -->

## references
- pyblish forum https://forums.pyblish.com/t/pyblish-unreal-engine/746
