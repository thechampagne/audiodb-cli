# audiodb-cli

[![](https://img.shields.io/github/v/tag/thechampagne/audiodb-cli?label=version)](https://github.com/thechampagne/audiodb-cli/releases/latest) [![](https://img.shields.io/github/license/thechampagne/audiodb-cli)](https://github.com/thechampagne/audiodb-cli/blob/main/LICENSE)

TheAudioDB cli.

### Download
Latest Release: [GitHub Release](https://github.com/thechampagne/audiodb-cli/releases/latest)

### Usage
```
audiodb -d [ARTIST NAME]
        (Discography for an Artist with Album names and year only)
or  audiodb --artist [ARTIST NAME]
        (Artist details from artist name)
or  audiodb --artist-id [ARTIST ID]
        (individual Artist details using known Artist ID)
or  audiodb --album-id [ALBUM ID]
        (individual Album info using known Album ID)
or  audiodb --albums-artist-id [ARTIST ID]
        (All Albums for an Artist using known Artist ID)
or  audiodb --track-id [TRACK ID]
        (individual track info using a known Track ID)
or  audiodb --tracks-album-id [ALBUM ID]
        (All Tracks for Album from known Album ID)
or  audiodb --mv-artist-id [ARTIST ID]
        (all the Music videos for a known Artist ID)
```

### Build

#### 1. Clone the repository
```
git clone https://github.com/thechampagne/audiodb-cli.git
```
#### 2. Navigate to the root
```
cd audiodb-cli
```
#### 3. Build the project
```
make
```
#### 4. Run test
```
make test
```

### Requirements
 - [audiodb-cgo](https://github.com/thechampagne/audiodb-cgo)

### License

This repo is released under the [Apache License 2.0](https://github.com/thechampagne/audiodb-cli/blob/main/LICENSE).
```
 Copyright 2022 XXIV

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

     http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
```