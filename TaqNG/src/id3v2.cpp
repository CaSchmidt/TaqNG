/****************************************************************************
** Copyright (c) 2005-2014, Carsten Schmidt. All rights reserved.
**
** Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions
** are met:
**
** 1. Redistributions of source code must retain the above copyright
**    notice, this list of conditions and the following disclaimer.
**
** 2. Redistributions in binary form must reproduce the above copyright
**    notice, this list of conditions and the following disclaimer in the
**    documentation and/or other materials provided with the distribution.
**
** 3. Neither the name of the copyright holder nor the names of its
**    contributors may be used to endorse or promote products derived from
**    this software without specific prior written permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*****************************************************************************/

#include "taq/id3v2.h"

namespace ID3v2 {

  ////// Global ///////////////////////////////////////////////////////////////

  const ID3v2Frames frames;

  ////// public ///////////////////////////////////////////////////////////////

  ID3v2Frames::ID3v2Frames()
    : QMap<QByteArray, QString>()
  {
    // 4.2.1. Identification frames ///////////////////////////////////////////

    insert(QByteArray("TIT1"), QStringLiteral("Content group description"));
    insert(QByteArray("TIT2"), QStringLiteral("Title/Songname/Content description"));
    insert(QByteArray("TIT3"), QStringLiteral("Subtitle/Description refinement"));
    insert(QByteArray("TALB"), QStringLiteral("Album/Movie/Show title"));
    insert(QByteArray("TOAL"), QStringLiteral("Original album/movie/show title"));
    insert(QByteArray("TRCK"), QStringLiteral("Track number/Position in set"));
    insert(QByteArray("TPOS"), QStringLiteral("Part of a set"));
    insert(QByteArray("TSST"), QStringLiteral("Set subtitle"));
    insert(QByteArray("TSRC"), QStringLiteral("ISRC"));

    // 4.2.2. Involved persons frames /////////////////////////////////////////

    insert(QByteArray("TPE1"),
     QStringLiteral("Lead artist/Lead performer/Soloist/Performing group"));
    insert(QByteArray("TPE2"), QStringLiteral("Band/Orchestra/Accompaniment"));
    insert(QByteArray("TPE3"), QStringLiteral("Conductor"));
    insert(QByteArray("TPE4"),
     QStringLiteral("Interpreted, remixed, or otherwise modified by"));
    insert(QByteArray("TOPE"), QStringLiteral("Original artist/performer"));
    insert(QByteArray("TEXT"), QStringLiteral("Lyricist/Text writer"));
    insert(QByteArray("TOLY"), QStringLiteral("Original lyricist/text writer"));
    insert(QByteArray("TCOM"), QStringLiteral("Composer"));
    insert(QByteArray("TMCL"), QStringLiteral("Musician credits list"));
    insert(QByteArray("TIPL"), QStringLiteral("Involved people list"));
    insert(QByteArray("TENC"), QStringLiteral("Encoded by"));

    // 4.2.3. Derived and subjective properties frames ////////////////////////

    insert(QByteArray("TBPM"), QStringLiteral("BPM"));
    insert(QByteArray("TLEN"), QStringLiteral("Length"));
    insert(QByteArray("TKEY"), QStringLiteral("Initial key"));
    insert(QByteArray("TLAN"), QStringLiteral("Language"));
    insert(QByteArray("TCON"), QStringLiteral("Content type"));
    insert(QByteArray("TFLT"), QStringLiteral("File type"));
    insert(QByteArray("TMED"), QStringLiteral("Media type"));
    insert(QByteArray("TMOO"), QStringLiteral("Mood"));

    // 4.2.4. Rights and license frames ///////////////////////////////////////

    insert(QByteArray("TCOP"), QStringLiteral("Copyright message"));
    insert(QByteArray("TPRO"), QStringLiteral("Produced notice"));
    insert(QByteArray("TPUB"), QStringLiteral("Publisher"));
    insert(QByteArray("TOWN"), QStringLiteral("File owner/licensee"));
    insert(QByteArray("TRSN"), QStringLiteral("Internet radio station name"));
    insert(QByteArray("TRSO"), QStringLiteral("Internet radio station owner"));

    // 4.2.5. Other text frames ///////////////////////////////////////////////

    insert(QByteArray("TOFN"), QStringLiteral("Original filename"));
    insert(QByteArray("TDLY"), QStringLiteral("Playlist delay"));
    insert(QByteArray("TDEN"), QStringLiteral("Encoding time"));
    insert(QByteArray("TDOR"), QStringLiteral("Original release time"));
    insert(QByteArray("TDRC"), QStringLiteral("Recording time"));
    insert(QByteArray("TDRL"), QStringLiteral("Release time"));
    insert(QByteArray("TDTG"), QStringLiteral("Tagging time"));
    insert(QByteArray("TSSE"),
     QStringLiteral("Software/Hardware and settings used for encoding"));
    insert(QByteArray("TSOA"), QStringLiteral("Album sort order"));
    insert(QByteArray("TSOP"), QStringLiteral("Performer sort order"));
    insert(QByteArray("TSOT"), QStringLiteral("Title sort order"));
  }

  ID3v2Frames::~ID3v2Frames()
  {
  }

}; // namespace ID3v2
