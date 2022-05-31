/*
 * Copyright 2022 XXIV
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <audiodb.h>

#include <cstdlib>
#include <cstring>
#include <iostream>

#define println(V) std::cout << V << std::endl
#define FLAG 1

bool index_exists(int length, int index) {
  return index >= 0 && index < length;
}

void usage() {
  println("audiodb -d [ARTIST NAME]");
  println("        (Discography for an Artist with Album names and year only)");
  println("or  audiodb --artist [ARTIST NAME]");
  println("        (Artist details from artist name)");
  println("or  audiodb --artist-id [ARTIST ID]");
  println("        (individual Artist details using known Artist ID)");
  println("or  audiodb --album-id [ALBUM ID]");
  println("        (individual Album info using known Album ID)");
  println("or  audiodb --albums-artist-id [ARTIST ID]");
  println("        (All Albums for an Artist using known Artist ID)");
  println("or  audiodb --track-id [TRACK ID]");
  println("        (individual track info using a known Track ID)");
  println("or  audiodb --tracks-album-id [ALBUM ID]");
  println("        (All Tracks for Album from known Album ID)");
  println("or  audiodb --mv-artist-id [ARTIST ID]");
  println("        (all the Music videos for a known Artist ID)");
}

void discography(char* s) {
  audiodb* res = audiodb_discography(s);
  if (res->error != NULL) {
    fprintf(stderr, "Something went wrong: No results found\n");
    free(res->error);
    exit(1);
  }
  for (int i = 0; i < res->buffer_length; i++) {
    std::cout << "Album: "
              << ((audiodb_discography_t**)res->buffer)[i]->str_album
              << std::endl;
    std::cout << "Year Release: "
              << ((audiodb_discography_t**)res->buffer)[i]->int_year_released
              << std::endl;
  }
  audiodb_discography_clean((audiodb_discography_t**)res->buffer,
                            res->buffer_length);
}

void search_artist(char* s) {
  audiodb* res = audiodb_search_artist(s);
  if (res->error != NULL) {
    fprintf(stderr, "Something went wrong: No results found\n");
    free(res->error);
    exit(1);
  }
  if (((audiodb_artist*)res->buffer)->id_artist != NULL &&
      strlen(((audiodb_artist*)res->buffer)->id_artist) != 0) {
    std::cout << "Artist: " << ((audiodb_artist*)res->buffer)->id_artist
              << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->id_label != NULL &&
      strlen(((audiodb_artist*)res->buffer)->id_label) != 0) {
    std::cout << "Label: " << ((audiodb_artist*)res->buffer)->id_label
              << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->int_bornyear != NULL &&
      strlen(((audiodb_artist*)res->buffer)->int_bornyear) != 0) {
    std::cout << "Bornyear: " << ((audiodb_artist*)res->buffer)->int_bornyear
              << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->int_charted != NULL &&
      strlen(((audiodb_artist*)res->buffer)->int_charted) != 0) {
    std::cout << "Charted: " << ((audiodb_artist*)res->buffer)->int_charted
              << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->int_diedyear != NULL &&
      strlen(((audiodb_artist*)res->buffer)->int_diedyear) != 0) {
    std::cout << "Diedyear: " << ((audiodb_artist*)res->buffer)->int_diedyear
              << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->int_formedyear != NULL &&
      strlen(((audiodb_artist*)res->buffer)->int_formedyear) != 0) {
    std::cout << "Formedyear: "
              << ((audiodb_artist*)res->buffer)->int_formedyear << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->int_members != NULL &&
      strlen(((audiodb_artist*)res->buffer)->int_members) != 0) {
    std::cout << "Members: " << ((audiodb_artist*)res->buffer)->int_members
              << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_artist != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_artist) != 0) {
    std::cout << "Artist: " << ((audiodb_artist*)res->buffer)->str_artist
              << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_artist_alternate != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_artist_alternate) != 0) {
    std::cout << "Artist_alternate: "
              << ((audiodb_artist*)res->buffer)->str_artist_alternate
              << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_artistbanner != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_artistbanner) != 0) {
    std::cout << "Artistbanner: "
              << ((audiodb_artist*)res->buffer)->str_artistbanner << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_artistclearart != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_artistclearart) != 0) {
    std::cout << "Artistclearart: "
              << ((audiodb_artist*)res->buffer)->str_artistclearart
              << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_artistcutout != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_artistcutout) != 0) {
    std::cout << "Artistcutout: "
              << ((audiodb_artist*)res->buffer)->str_artistcutout << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_artistfanart != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_artistfanart) != 0) {
    std::cout << "Artistfanart: "
              << ((audiodb_artist*)res->buffer)->str_artistfanart << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_artistfanart2 != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_artistfanart2) != 0) {
    std::cout << "Artistfanart2: "
              << ((audiodb_artist*)res->buffer)->str_artistfanart2 << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_artistfanart3 != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_artistfanart3) != 0) {
    std::cout << "Artistfanart3: "
              << ((audiodb_artist*)res->buffer)->str_artistfanart3 << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_artistfanart4 != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_artistfanart4) != 0) {
    std::cout << "Artistfanart4: "
              << ((audiodb_artist*)res->buffer)->str_artistfanart4 << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_artistlogo != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_artistlogo) != 0) {
    std::cout << "Artistlogo: "
              << ((audiodb_artist*)res->buffer)->str_artistlogo << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_artist_stripped != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_artist_stripped) != 0) {
    std::cout << "Artist_stripped: "
              << ((audiodb_artist*)res->buffer)->str_artist_stripped
              << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_artist_thumb != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_artist_thumb) != 0) {
    std::cout << "Artist_thumb: "
              << ((audiodb_artist*)res->buffer)->str_artist_thumb << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_artist_wide_thumb != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_artist_wide_thumb) != 0) {
    std::cout << "Artist_wide_thumb: "
              << ((audiodb_artist*)res->buffer)->str_artist_wide_thumb
              << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_biographycn != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_biographycn) != 0) {
    std::cout << "Biographycn: "
              << ((audiodb_artist*)res->buffer)->str_biographycn << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_biographyde != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_biographyde) != 0) {
    std::cout << "Biographyde: "
              << ((audiodb_artist*)res->buffer)->str_biographyde << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_biographyen != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_biographyen) != 0) {
    std::cout << "Biographyen: "
              << ((audiodb_artist*)res->buffer)->str_biographyen << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_biographyes != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_biographyes) != 0) {
    std::cout << "Biographyes: "
              << ((audiodb_artist*)res->buffer)->str_biographyes << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_biographyfr != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_biographyfr) != 0) {
    std::cout << "Biographyfr: "
              << ((audiodb_artist*)res->buffer)->str_biographyfr << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_biographyhu != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_biographyhu) != 0) {
    std::cout << "Biographyhu: "
              << ((audiodb_artist*)res->buffer)->str_biographyhu << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_biographyil != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_biographyil) != 0) {
    std::cout << "Biographyil: "
              << ((audiodb_artist*)res->buffer)->str_biographyil << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_biographyit != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_biographyit) != 0) {
    std::cout << "Biographyit: "
              << ((audiodb_artist*)res->buffer)->str_biographyit << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_biographyjp != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_biographyjp) != 0) {
    std::cout << "Biographyjp: "
              << ((audiodb_artist*)res->buffer)->str_biographyjp << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_biographynl != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_biographynl) != 0) {
    std::cout << "Biographynl: "
              << ((audiodb_artist*)res->buffer)->str_biographynl << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_biographyno != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_biographyno) != 0) {
    std::cout << "Biographyno: "
              << ((audiodb_artist*)res->buffer)->str_biographyno << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_biographypl != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_biographypl) != 0) {
    std::cout << "Biographypl: "
              << ((audiodb_artist*)res->buffer)->str_biographypl << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_biographypt != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_biographypt) != 0) {
    std::cout << "Biographypt: "
              << ((audiodb_artist*)res->buffer)->str_biographypt << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_biographyru != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_biographyru) != 0) {
    std::cout << "Biographyru: "
              << ((audiodb_artist*)res->buffer)->str_biographyru << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_biographyse != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_biographyse) != 0) {
    std::cout << "Biographyse: "
              << ((audiodb_artist*)res->buffer)->str_biographyse << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_country != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_country) != 0) {
    std::cout << "Country: " << ((audiodb_artist*)res->buffer)->str_country
              << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_countrycode != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_countrycode) != 0) {
    std::cout << "Countrycode: "
              << ((audiodb_artist*)res->buffer)->str_countrycode << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_disbanded != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_disbanded) != 0) {
    std::cout << "Disbanded: " << ((audiodb_artist*)res->buffer)->str_disbanded
              << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_facebook != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_facebook) != 0) {
    std::cout << "Facebook: " << ((audiodb_artist*)res->buffer)->str_facebook
              << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_gender != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_gender) != 0) {
    std::cout << "Gender: " << ((audiodb_artist*)res->buffer)->str_gender
              << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_genre != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_genre) != 0) {
    std::cout << "Genre: " << ((audiodb_artist*)res->buffer)->str_genre
              << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_isnicode != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_isnicode) != 0) {
    std::cout << "Isnicode: " << ((audiodb_artist*)res->buffer)->str_isnicode
              << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_label != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_label) != 0) {
    std::cout << "Label: " << ((audiodb_artist*)res->buffer)->str_label
              << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_lastfmchart != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_lastfmchart) != 0) {
    std::cout << "Lastfmchart: "
              << ((audiodb_artist*)res->buffer)->str_lastfmchart << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_locked != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_locked) != 0) {
    std::cout << "Locked: " << ((audiodb_artist*)res->buffer)->str_locked
              << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_mood != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_mood) != 0) {
    std::cout << "Mood: " << ((audiodb_artist*)res->buffer)->str_mood
              << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_music_brainz_id != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_music_brainz_id) != 0) {
    std::cout << "Music_brainz_id: "
              << ((audiodb_artist*)res->buffer)->str_music_brainz_id
              << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_style != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_style) != 0) {
    std::cout << "Style: " << ((audiodb_artist*)res->buffer)->str_style
              << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_twitter != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_twitter) != 0) {
    std::cout << "Twitter: " << ((audiodb_artist*)res->buffer)->str_twitter
              << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_website != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_website) != 0) {
    std::cout << "Website: " << ((audiodb_artist*)res->buffer)->str_website
              << std::endl;
  }

  audiodb_artist_clean((audiodb_artist*)res->buffer);
}

void search_artist_id(char* s) {
  audiodb* res = audiodb_search_artist_by_id(atoi(s));
  if (res->error != NULL) {
    fprintf(stderr, "Something went wrong: No results found\n");
    free(res->error);
    exit(1);
  }
  if (((audiodb_artist*)res->buffer)->id_artist != NULL &&
      strlen(((audiodb_artist*)res->buffer)->id_artist) != 0) {
    std::cout << "Artist: " << ((audiodb_artist*)res->buffer)->id_artist
              << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->id_label != NULL &&
      strlen(((audiodb_artist*)res->buffer)->id_label) != 0) {
    std::cout << "Label: " << ((audiodb_artist*)res->buffer)->id_label
              << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->int_bornyear != NULL &&
      strlen(((audiodb_artist*)res->buffer)->int_bornyear) != 0) {
    std::cout << "Bornyear: " << ((audiodb_artist*)res->buffer)->int_bornyear
              << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->int_charted != NULL &&
      strlen(((audiodb_artist*)res->buffer)->int_charted) != 0) {
    std::cout << "Charted: " << ((audiodb_artist*)res->buffer)->int_charted
              << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->int_diedyear != NULL &&
      strlen(((audiodb_artist*)res->buffer)->int_diedyear) != 0) {
    std::cout << "Diedyear: " << ((audiodb_artist*)res->buffer)->int_diedyear
              << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->int_formedyear != NULL &&
      strlen(((audiodb_artist*)res->buffer)->int_formedyear) != 0) {
    std::cout << "Formedyear: "
              << ((audiodb_artist*)res->buffer)->int_formedyear << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->int_members != NULL &&
      strlen(((audiodb_artist*)res->buffer)->int_members) != 0) {
    std::cout << "Members: " << ((audiodb_artist*)res->buffer)->int_members
              << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_artist != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_artist) != 0) {
    std::cout << "Artist: " << ((audiodb_artist*)res->buffer)->str_artist
              << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_artist_alternate != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_artist_alternate) != 0) {
    std::cout << "Artist_alternate: "
              << ((audiodb_artist*)res->buffer)->str_artist_alternate
              << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_artistbanner != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_artistbanner) != 0) {
    std::cout << "Artistbanner: "
              << ((audiodb_artist*)res->buffer)->str_artistbanner << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_artistclearart != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_artistclearart) != 0) {
    std::cout << "Artistclearart: "
              << ((audiodb_artist*)res->buffer)->str_artistclearart
              << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_artistcutout != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_artistcutout) != 0) {
    std::cout << "Artistcutout: "
              << ((audiodb_artist*)res->buffer)->str_artistcutout << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_artistfanart != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_artistfanart) != 0) {
    std::cout << "Artistfanart: "
              << ((audiodb_artist*)res->buffer)->str_artistfanart << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_artistfanart2 != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_artistfanart2) != 0) {
    std::cout << "Artistfanart2: "
              << ((audiodb_artist*)res->buffer)->str_artistfanart2 << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_artistfanart3 != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_artistfanart3) != 0) {
    std::cout << "Artistfanart3: "
              << ((audiodb_artist*)res->buffer)->str_artistfanart3 << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_artistfanart4 != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_artistfanart4) != 0) {
    std::cout << "Artistfanart4: "
              << ((audiodb_artist*)res->buffer)->str_artistfanart4 << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_artistlogo != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_artistlogo) != 0) {
    std::cout << "Artistlogo: "
              << ((audiodb_artist*)res->buffer)->str_artistlogo << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_artist_stripped != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_artist_stripped) != 0) {
    std::cout << "Artist_stripped: "
              << ((audiodb_artist*)res->buffer)->str_artist_stripped
              << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_artist_thumb != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_artist_thumb) != 0) {
    std::cout << "Artist_thumb: "
              << ((audiodb_artist*)res->buffer)->str_artist_thumb << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_artist_wide_thumb != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_artist_wide_thumb) != 0) {
    std::cout << "Artist_wide_thumb: "
              << ((audiodb_artist*)res->buffer)->str_artist_wide_thumb
              << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_biographycn != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_biographycn) != 0) {
    std::cout << "Biographycn: "
              << ((audiodb_artist*)res->buffer)->str_biographycn << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_biographyde != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_biographyde) != 0) {
    std::cout << "Biographyde: "
              << ((audiodb_artist*)res->buffer)->str_biographyde << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_biographyen != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_biographyen) != 0) {
    std::cout << "Biographyen: "
              << ((audiodb_artist*)res->buffer)->str_biographyen << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_biographyes != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_biographyes) != 0) {
    std::cout << "Biographyes: "
              << ((audiodb_artist*)res->buffer)->str_biographyes << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_biographyfr != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_biographyfr) != 0) {
    std::cout << "Biographyfr: "
              << ((audiodb_artist*)res->buffer)->str_biographyfr << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_biographyhu != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_biographyhu) != 0) {
    std::cout << "Biographyhu: "
              << ((audiodb_artist*)res->buffer)->str_biographyhu << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_biographyil != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_biographyil) != 0) {
    std::cout << "Biographyil: "
              << ((audiodb_artist*)res->buffer)->str_biographyil << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_biographyit != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_biographyit) != 0) {
    std::cout << "Biographyit: "
              << ((audiodb_artist*)res->buffer)->str_biographyit << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_biographyjp != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_biographyjp) != 0) {
    std::cout << "Biographyjp: "
              << ((audiodb_artist*)res->buffer)->str_biographyjp << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_biographynl != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_biographynl) != 0) {
    std::cout << "Biographynl: "
              << ((audiodb_artist*)res->buffer)->str_biographynl << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_biographyno != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_biographyno) != 0) {
    std::cout << "Biographyno: "
              << ((audiodb_artist*)res->buffer)->str_biographyno << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_biographypl != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_biographypl) != 0) {
    std::cout << "Biographypl: "
              << ((audiodb_artist*)res->buffer)->str_biographypl << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_biographypt != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_biographypt) != 0) {
    std::cout << "Biographypt: "
              << ((audiodb_artist*)res->buffer)->str_biographypt << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_biographyru != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_biographyru) != 0) {
    std::cout << "Biographyru: "
              << ((audiodb_artist*)res->buffer)->str_biographyru << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_biographyse != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_biographyse) != 0) {
    std::cout << "Biographyse: "
              << ((audiodb_artist*)res->buffer)->str_biographyse << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_country != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_country) != 0) {
    std::cout << "Country: " << ((audiodb_artist*)res->buffer)->str_country
              << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_countrycode != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_countrycode) != 0) {
    std::cout << "Countrycode: "
              << ((audiodb_artist*)res->buffer)->str_countrycode << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_disbanded != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_disbanded) != 0) {
    std::cout << "Disbanded: " << ((audiodb_artist*)res->buffer)->str_disbanded
              << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_facebook != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_facebook) != 0) {
    std::cout << "Facebook: " << ((audiodb_artist*)res->buffer)->str_facebook
              << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_gender != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_gender) != 0) {
    std::cout << "Gender: " << ((audiodb_artist*)res->buffer)->str_gender
              << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_genre != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_genre) != 0) {
    std::cout << "Genre: " << ((audiodb_artist*)res->buffer)->str_genre
              << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_isnicode != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_isnicode) != 0) {
    std::cout << "Isnicode: " << ((audiodb_artist*)res->buffer)->str_isnicode
              << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_label != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_label) != 0) {
    std::cout << "Label: " << ((audiodb_artist*)res->buffer)->str_label
              << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_lastfmchart != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_lastfmchart) != 0) {
    std::cout << "Lastfmchart: "
              << ((audiodb_artist*)res->buffer)->str_lastfmchart << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_locked != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_locked) != 0) {
    std::cout << "Locked: " << ((audiodb_artist*)res->buffer)->str_locked
              << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_mood != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_mood) != 0) {
    std::cout << "Mood: " << ((audiodb_artist*)res->buffer)->str_mood
              << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_music_brainz_id != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_music_brainz_id) != 0) {
    std::cout << "Music_brainz_id: "
              << ((audiodb_artist*)res->buffer)->str_music_brainz_id
              << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_style != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_style) != 0) {
    std::cout << "Style: " << ((audiodb_artist*)res->buffer)->str_style
              << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_twitter != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_twitter) != 0) {
    std::cout << "Twitter: " << ((audiodb_artist*)res->buffer)->str_twitter
              << std::endl;
  }
  if (((audiodb_artist*)res->buffer)->str_website != NULL &&
      strlen(((audiodb_artist*)res->buffer)->str_website) != 0) {
    std::cout << "Website: " << ((audiodb_artist*)res->buffer)->str_website
              << std::endl;
  }

  audiodb_artist_clean((audiodb_artist*)res->buffer);
}

void search_album_id(char* s) {
  audiodb* res = audiodb_search_album_by_id(atoi(s));
  if (res->error != NULL) {
    fprintf(stderr, "Something went wrong: No results found\n");
    free(res->error);
    exit(1);
  }

  if (((audiodb_album*)res->buffer)->id_album != NULL &&
      strlen(((audiodb_album*)res->buffer)->id_album) != 0) {
    std::cout << "Album: " << ((audiodb_album*)res->buffer)->id_album
              << std::endl;
  }
  if (((audiodb_album*)res->buffer)->id_artist != NULL &&
      strlen(((audiodb_album*)res->buffer)->id_artist) != 0) {
    std::cout << "Artist: " << ((audiodb_album*)res->buffer)->id_artist
              << std::endl;
  }
  if (((audiodb_album*)res->buffer)->id_label != NULL &&
      strlen(((audiodb_album*)res->buffer)->id_label) != 0) {
    std::cout << "Label: " << ((audiodb_album*)res->buffer)->id_label
              << std::endl;
  }
  if (((audiodb_album*)res->buffer)->int_loved != NULL &&
      strlen(((audiodb_album*)res->buffer)->int_loved) != 0) {
    std::cout << "Loved: " << ((audiodb_album*)res->buffer)->int_loved
              << std::endl;
  }
  if (((audiodb_album*)res->buffer)->int_sales != NULL &&
      strlen(((audiodb_album*)res->buffer)->int_sales) != 0) {
    std::cout << "Sales: " << ((audiodb_album*)res->buffer)->int_sales
              << std::endl;
  }
  if (((audiodb_album*)res->buffer)->int_score != NULL &&
      strlen(((audiodb_album*)res->buffer)->int_score) != 0) {
    std::cout << "Score: " << ((audiodb_album*)res->buffer)->int_score
              << std::endl;
  }
  if (((audiodb_album*)res->buffer)->int_score_votes != NULL &&
      strlen(((audiodb_album*)res->buffer)->int_score_votes) != 0) {
    std::cout << "Score_votes: "
              << ((audiodb_album*)res->buffer)->int_score_votes << std::endl;
  }
  if (((audiodb_album*)res->buffer)->int_year_released != NULL &&
      strlen(((audiodb_album*)res->buffer)->int_year_released) != 0) {
    std::cout << "Year_released: "
              << ((audiodb_album*)res->buffer)->int_year_released << std::endl;
  }
  if (((audiodb_album*)res->buffer)->str_album != NULL &&
      strlen(((audiodb_album*)res->buffer)->str_album) != 0) {
    std::cout << "Album: " << ((audiodb_album*)res->buffer)->str_album
              << std::endl;
  }
  if (((audiodb_album*)res->buffer)->str_album3dcase != NULL &&
      strlen(((audiodb_album*)res->buffer)->str_album3dcase) != 0) {
    std::cout << "Album3dcase: "
              << ((audiodb_album*)res->buffer)->str_album3dcase << std::endl;
  }
  if (((audiodb_album*)res->buffer)->str_album3dface != NULL &&
      strlen(((audiodb_album*)res->buffer)->str_album3dface) != 0) {
    std::cout << "Album3dface: "
              << ((audiodb_album*)res->buffer)->str_album3dface << std::endl;
  }
  if (((audiodb_album*)res->buffer)->str_album3dflat != NULL &&
      strlen(((audiodb_album*)res->buffer)->str_album3dflat) != 0) {
    std::cout << "Album3dflat: "
              << ((audiodb_album*)res->buffer)->str_album3dflat << std::endl;
  }
  if (((audiodb_album*)res->buffer)->str_album3dthumb != NULL &&
      strlen(((audiodb_album*)res->buffer)->str_album3dthumb) != 0) {
    std::cout << "Album3dthumb: "
              << ((audiodb_album*)res->buffer)->str_album3dthumb << std::endl;
  }
  if (((audiodb_album*)res->buffer)->str_albumcdart != NULL &&
      strlen(((audiodb_album*)res->buffer)->str_albumcdart) != 0) {
    std::cout << "Albumcdart: " << ((audiodb_album*)res->buffer)->str_albumcdart
              << std::endl;
  }
  if (((audiodb_album*)res->buffer)->str_albumspine != NULL &&
      strlen(((audiodb_album*)res->buffer)->str_albumspine) != 0) {
    std::cout << "Albumspine: " << ((audiodb_album*)res->buffer)->str_albumspine
              << std::endl;
  }
  if (((audiodb_album*)res->buffer)->str_albumstripped != NULL &&
      strlen(((audiodb_album*)res->buffer)->str_albumstripped) != 0) {
    std::cout << "Albumstripped: "
              << ((audiodb_album*)res->buffer)->str_albumstripped << std::endl;
  }
  if (((audiodb_album*)res->buffer)->str_albumthumb != NULL &&
      strlen(((audiodb_album*)res->buffer)->str_albumthumb) != 0) {
    std::cout << "Albumthumb: " << ((audiodb_album*)res->buffer)->str_albumthumb
              << std::endl;
  }
  if (((audiodb_album*)res->buffer)->str_albumthumbback != NULL &&
      strlen(((audiodb_album*)res->buffer)->str_albumthumbback) != 0) {
    std::cout << "Albumthumbback: "
              << ((audiodb_album*)res->buffer)->str_albumthumbback << std::endl;
  }
  if (((audiodb_album*)res->buffer)->str_albumthumbhq != NULL &&
      strlen(((audiodb_album*)res->buffer)->str_albumthumbhq) != 0) {
    std::cout << "Albumthumbhq: "
              << ((audiodb_album*)res->buffer)->str_albumthumbhq << std::endl;
  }
  if (((audiodb_album*)res->buffer)->str_allmusicid != NULL &&
      strlen(((audiodb_album*)res->buffer)->str_allmusicid) != 0) {
    std::cout << "Allmusicid: " << ((audiodb_album*)res->buffer)->str_allmusicid
              << std::endl;
  }
  if (((audiodb_album*)res->buffer)->str_amazonid != NULL &&
      strlen(((audiodb_album*)res->buffer)->str_amazonid) != 0) {
    std::cout << "Amazonid: " << ((audiodb_album*)res->buffer)->str_amazonid
              << std::endl;
  }
  if (((audiodb_album*)res->buffer)->str_artist != NULL &&
      strlen(((audiodb_album*)res->buffer)->str_artist) != 0) {
    std::cout << "Artist: " << ((audiodb_album*)res->buffer)->str_artist
              << std::endl;
  }
  if (((audiodb_album*)res->buffer)->str_artist_stripped != NULL &&
      strlen(((audiodb_album*)res->buffer)->str_artist_stripped) != 0) {
    std::cout << "Artist_stripped: "
              << ((audiodb_album*)res->buffer)->str_artist_stripped
              << std::endl;
  }
  if (((audiodb_album*)res->buffer)->str_bbcreviewid != NULL &&
      strlen(((audiodb_album*)res->buffer)->str_bbcreviewid) != 0) {
    std::cout << "Bbcreviewid: "
              << ((audiodb_album*)res->buffer)->str_bbcreviewid << std::endl;
  }
  if (((audiodb_album*)res->buffer)->str_description != NULL &&
      strlen(((audiodb_album*)res->buffer)->str_description) != 0) {
    std::cout << "Description: "
              << ((audiodb_album*)res->buffer)->str_description << std::endl;
  }
  if (((audiodb_album*)res->buffer)->str_descriptioncn != NULL &&
      strlen(((audiodb_album*)res->buffer)->str_descriptioncn) != 0) {
    std::cout << "Descriptioncn: "
              << ((audiodb_album*)res->buffer)->str_descriptioncn << std::endl;
  }
  if (((audiodb_album*)res->buffer)->str_descriptionde != NULL &&
      strlen(((audiodb_album*)res->buffer)->str_descriptionde) != 0) {
    std::cout << "Descriptionde: "
              << ((audiodb_album*)res->buffer)->str_descriptionde << std::endl;
  }
  if (((audiodb_album*)res->buffer)->str_descriptionen != NULL &&
      strlen(((audiodb_album*)res->buffer)->str_descriptionen) != 0) {
    std::cout << "Descriptionen: "
              << ((audiodb_album*)res->buffer)->str_descriptionen << std::endl;
  }
  if (((audiodb_album*)res->buffer)->str_descriptiones != NULL &&
      strlen(((audiodb_album*)res->buffer)->str_descriptiones) != 0) {
    std::cout << "Descriptiones: "
              << ((audiodb_album*)res->buffer)->str_descriptiones << std::endl;
  }
  if (((audiodb_album*)res->buffer)->str_descriptionfr != NULL &&
      strlen(((audiodb_album*)res->buffer)->str_descriptionfr) != 0) {
    std::cout << "Descriptionfr: "
              << ((audiodb_album*)res->buffer)->str_descriptionfr << std::endl;
  }
  if (((audiodb_album*)res->buffer)->str_descriptionhu != NULL &&
      strlen(((audiodb_album*)res->buffer)->str_descriptionhu) != 0) {
    std::cout << "Descriptionhu: "
              << ((audiodb_album*)res->buffer)->str_descriptionhu << std::endl;
  }
  if (((audiodb_album*)res->buffer)->str_descriptionil != NULL &&
      strlen(((audiodb_album*)res->buffer)->str_descriptionil) != 0) {
    std::cout << "Descriptionil: "
              << ((audiodb_album*)res->buffer)->str_descriptionil << std::endl;
  }
  if (((audiodb_album*)res->buffer)->str_descriptionit != NULL &&
      strlen(((audiodb_album*)res->buffer)->str_descriptionit) != 0) {
    std::cout << "Descriptionit: "
              << ((audiodb_album*)res->buffer)->str_descriptionit << std::endl;
  }
  if (((audiodb_album*)res->buffer)->str_descriptionjp != NULL &&
      strlen(((audiodb_album*)res->buffer)->str_descriptionjp) != 0) {
    std::cout << "Descriptionjp: "
              << ((audiodb_album*)res->buffer)->str_descriptionjp << std::endl;
  }
  if (((audiodb_album*)res->buffer)->str_descriptionnl != NULL &&
      strlen(((audiodb_album*)res->buffer)->str_descriptionnl) != 0) {
    std::cout << "Descriptionnl: "
              << ((audiodb_album*)res->buffer)->str_descriptionnl << std::endl;
  }
  if (((audiodb_album*)res->buffer)->str_descriptionno != NULL &&
      strlen(((audiodb_album*)res->buffer)->str_descriptionno) != 0) {
    std::cout << "Descriptionno: "
              << ((audiodb_album*)res->buffer)->str_descriptionno << std::endl;
  }
  if (((audiodb_album*)res->buffer)->str_descriptionpl != NULL &&
      strlen(((audiodb_album*)res->buffer)->str_descriptionpl) != 0) {
    std::cout << "Descriptionpl: "
              << ((audiodb_album*)res->buffer)->str_descriptionpl << std::endl;
  }
  if (((audiodb_album*)res->buffer)->str_descriptionpt != NULL &&
      strlen(((audiodb_album*)res->buffer)->str_descriptionpt) != 0) {
    std::cout << "Descriptionpt: "
              << ((audiodb_album*)res->buffer)->str_descriptionpt << std::endl;
  }
  if (((audiodb_album*)res->buffer)->str_descriptionru != NULL &&
      strlen(((audiodb_album*)res->buffer)->str_descriptionru) != 0) {
    std::cout << "Descriptionru: "
              << ((audiodb_album*)res->buffer)->str_descriptionru << std::endl;
  }
  if (((audiodb_album*)res->buffer)->str_descriptionse != NULL &&
      strlen(((audiodb_album*)res->buffer)->str_descriptionse) != 0) {
    std::cout << "Descriptionse: "
              << ((audiodb_album*)res->buffer)->str_descriptionse << std::endl;
  }
  if (((audiodb_album*)res->buffer)->str_discogsid != NULL &&
      strlen(((audiodb_album*)res->buffer)->str_discogsid) != 0) {
    std::cout << "Discogsid: " << ((audiodb_album*)res->buffer)->str_discogsid
              << std::endl;
  }
  if (((audiodb_album*)res->buffer)->str_geniusid != NULL &&
      strlen(((audiodb_album*)res->buffer)->str_geniusid) != 0) {
    std::cout << "Geniusid: " << ((audiodb_album*)res->buffer)->str_geniusid
              << std::endl;
  }
  if (((audiodb_album*)res->buffer)->str_genre != NULL &&
      strlen(((audiodb_album*)res->buffer)->str_genre) != 0) {
    std::cout << "Genre: " << ((audiodb_album*)res->buffer)->str_genre
              << std::endl;
  }
  if (((audiodb_album*)res->buffer)->str_itunesid != NULL &&
      strlen(((audiodb_album*)res->buffer)->str_itunesid) != 0) {
    std::cout << "Itunesid: " << ((audiodb_album*)res->buffer)->str_itunesid
              << std::endl;
  }
  if (((audiodb_album*)res->buffer)->str_label != NULL &&
      strlen(((audiodb_album*)res->buffer)->str_label) != 0) {
    std::cout << "Label: " << ((audiodb_album*)res->buffer)->str_label
              << std::endl;
  }
  if (((audiodb_album*)res->buffer)->str_location != NULL &&
      strlen(((audiodb_album*)res->buffer)->str_location) != 0) {
    std::cout << "Location: " << ((audiodb_album*)res->buffer)->str_location
              << std::endl;
  }
  if (((audiodb_album*)res->buffer)->str_locked != NULL &&
      strlen(((audiodb_album*)res->buffer)->str_locked) != 0) {
    std::cout << "Locked: " << ((audiodb_album*)res->buffer)->str_locked
              << std::endl;
  }
  if (((audiodb_album*)res->buffer)->str_lyricwikiid != NULL &&
      strlen(((audiodb_album*)res->buffer)->str_lyricwikiid) != 0) {
    std::cout << "Lyricwikiid: "
              << ((audiodb_album*)res->buffer)->str_lyricwikiid << std::endl;
  }
  if (((audiodb_album*)res->buffer)->str_mood != NULL &&
      strlen(((audiodb_album*)res->buffer)->str_mood) != 0) {
    std::cout << "Mood: " << ((audiodb_album*)res->buffer)->str_mood
              << std::endl;
  }
  if (((audiodb_album*)res->buffer)->str_music_brainz_artist_id != NULL &&
      strlen(((audiodb_album*)res->buffer)->str_music_brainz_artist_id) != 0) {
    std::cout << "Music_brainz_artist_id: "
              << ((audiodb_album*)res->buffer)->str_music_brainz_artist_id
              << std::endl;
  }
  if (((audiodb_album*)res->buffer)->str_music_brainz_id != NULL &&
      strlen(((audiodb_album*)res->buffer)->str_music_brainz_id) != 0) {
    std::cout << "Music_brainz_id: "
              << ((audiodb_album*)res->buffer)->str_music_brainz_id
              << std::endl;
  }
  if (((audiodb_album*)res->buffer)->str_musicmozid != NULL &&
      strlen(((audiodb_album*)res->buffer)->str_musicmozid) != 0) {
    std::cout << "Musicmozid: " << ((audiodb_album*)res->buffer)->str_musicmozid
              << std::endl;
  }
  if (((audiodb_album*)res->buffer)->str_rate_your_music_id != NULL &&
      strlen(((audiodb_album*)res->buffer)->str_rate_your_music_id) != 0) {
    std::cout << "Rate_your_music_id: "
              << ((audiodb_album*)res->buffer)->str_rate_your_music_id
              << std::endl;
  }
  if (((audiodb_album*)res->buffer)->str_release_format != NULL &&
      strlen(((audiodb_album*)res->buffer)->str_release_format) != 0) {
    std::cout << "Release_format: "
              << ((audiodb_album*)res->buffer)->str_release_format << std::endl;
  }
  if (((audiodb_album*)res->buffer)->str_review != NULL &&
      strlen(((audiodb_album*)res->buffer)->str_review) != 0) {
    std::cout << "Review: " << ((audiodb_album*)res->buffer)->str_review
              << std::endl;
  }
  if (((audiodb_album*)res->buffer)->str_speed != NULL &&
      strlen(((audiodb_album*)res->buffer)->str_speed) != 0) {
    std::cout << "Speed: " << ((audiodb_album*)res->buffer)->str_speed
              << std::endl;
  }
  if (((audiodb_album*)res->buffer)->str_style != NULL &&
      strlen(((audiodb_album*)res->buffer)->str_style) != 0) {
    std::cout << "Style: " << ((audiodb_album*)res->buffer)->str_style
              << std::endl;
  }
  if (((audiodb_album*)res->buffer)->str_theme != NULL &&
      strlen(((audiodb_album*)res->buffer)->str_theme) != 0) {
    std::cout << "Theme: " << ((audiodb_album*)res->buffer)->str_theme
              << std::endl;
  }
  if (((audiodb_album*)res->buffer)->str_wikidataid != NULL &&
      strlen(((audiodb_album*)res->buffer)->str_wikidataid) != 0) {
    std::cout << "Wikidataid: " << ((audiodb_album*)res->buffer)->str_wikidataid
              << std::endl;
  }
  if (((audiodb_album*)res->buffer)->str_wikipediaid != NULL &&
      strlen(((audiodb_album*)res->buffer)->str_wikipediaid) != 0) {
    std::cout << "Wikipediaid: "
              << ((audiodb_album*)res->buffer)->str_wikipediaid << std::endl;
  }

  audiodb_album_clean((audiodb_album*)res->buffer);
}

void search_albums(char* s) {
  audiodb* res = audiodb_search_albums_by_artist_id(atoi(s));
  if (res->error != NULL) {
    fprintf(stderr, "Something went wrong: No results found\n");
    free(res->error);
    exit(1);
  }

  for (int i = 0; i < res->buffer_length; i++) {
    if (((audiodb_album**)res->buffer)[i]->id_album != NULL &&
        strlen(((audiodb_album**)res->buffer)[i]->id_album) != 0) {
      std::cout << "Album: " << ((audiodb_album**)res->buffer)[i]->id_album
                << std::endl;
    }
    if (((audiodb_album**)res->buffer)[i]->id_artist != NULL &&
        strlen(((audiodb_album**)res->buffer)[i]->id_artist) != 0) {
      std::cout << "Artist: " << ((audiodb_album**)res->buffer)[i]->id_artist
                << std::endl;
    }
    if (((audiodb_album**)res->buffer)[i]->id_label != NULL &&
        strlen(((audiodb_album**)res->buffer)[i]->id_label) != 0) {
      std::cout << "Label: " << ((audiodb_album**)res->buffer)[i]->id_label
                << std::endl;
    }
    if (((audiodb_album**)res->buffer)[i]->int_loved != NULL &&
        strlen(((audiodb_album**)res->buffer)[i]->int_loved) != 0) {
      std::cout << "Loved: " << ((audiodb_album**)res->buffer)[i]->int_loved
                << std::endl;
    }
    if (((audiodb_album**)res->buffer)[i]->int_sales != NULL &&
        strlen(((audiodb_album**)res->buffer)[i]->int_sales) != 0) {
      std::cout << "Sales: " << ((audiodb_album**)res->buffer)[i]->int_sales
                << std::endl;
    }
    if (((audiodb_album**)res->buffer)[i]->int_score != NULL &&
        strlen(((audiodb_album**)res->buffer)[i]->int_score) != 0) {
      std::cout << "Score: " << ((audiodb_album**)res->buffer)[i]->int_score
                << std::endl;
    }
    if (((audiodb_album**)res->buffer)[i]->int_score_votes != NULL &&
        strlen(((audiodb_album**)res->buffer)[i]->int_score_votes) != 0) {
      std::cout << "Score_votes: "
                << ((audiodb_album**)res->buffer)[i]->int_score_votes
                << std::endl;
    }
    if (((audiodb_album**)res->buffer)[i]->int_year_released != NULL &&
        strlen(((audiodb_album**)res->buffer)[i]->int_year_released) != 0) {
      std::cout << "Year_released: "
                << ((audiodb_album**)res->buffer)[i]->int_year_released
                << std::endl;
    }
    if (((audiodb_album**)res->buffer)[i]->str_album != NULL &&
        strlen(((audiodb_album**)res->buffer)[i]->str_album) != 0) {
      std::cout << "Album: " << ((audiodb_album**)res->buffer)[i]->str_album
                << std::endl;
    }
    if (((audiodb_album**)res->buffer)[i]->str_album3dcase != NULL &&
        strlen(((audiodb_album**)res->buffer)[i]->str_album3dcase) != 0) {
      std::cout << "Album3dcase: "
                << ((audiodb_album**)res->buffer)[i]->str_album3dcase
                << std::endl;
    }
    if (((audiodb_album**)res->buffer)[i]->str_album3dface != NULL &&
        strlen(((audiodb_album**)res->buffer)[i]->str_album3dface) != 0) {
      std::cout << "Album3dface: "
                << ((audiodb_album**)res->buffer)[i]->str_album3dface
                << std::endl;
    }
    if (((audiodb_album**)res->buffer)[i]->str_album3dflat != NULL &&
        strlen(((audiodb_album**)res->buffer)[i]->str_album3dflat) != 0) {
      std::cout << "Album3dflat: "
                << ((audiodb_album**)res->buffer)[i]->str_album3dflat
                << std::endl;
    }
    if (((audiodb_album**)res->buffer)[i]->str_album3dthumb != NULL &&
        strlen(((audiodb_album**)res->buffer)[i]->str_album3dthumb) != 0) {
      std::cout << "Album3dthumb: "
                << ((audiodb_album**)res->buffer)[i]->str_album3dthumb
                << std::endl;
    }
    if (((audiodb_album**)res->buffer)[i]->str_albumcdart != NULL &&
        strlen(((audiodb_album**)res->buffer)[i]->str_albumcdart) != 0) {
      std::cout << "Albumcdart: "
                << ((audiodb_album**)res->buffer)[i]->str_albumcdart
                << std::endl;
    }
    if (((audiodb_album**)res->buffer)[i]->str_albumspine != NULL &&
        strlen(((audiodb_album**)res->buffer)[i]->str_albumspine) != 0) {
      std::cout << "Albumspine: "
                << ((audiodb_album**)res->buffer)[i]->str_albumspine
                << std::endl;
    }
    if (((audiodb_album**)res->buffer)[i]->str_albumstripped != NULL &&
        strlen(((audiodb_album**)res->buffer)[i]->str_albumstripped) != 0) {
      std::cout << "Albumstripped: "
                << ((audiodb_album**)res->buffer)[i]->str_albumstripped
                << std::endl;
    }
    if (((audiodb_album**)res->buffer)[i]->str_albumthumb != NULL &&
        strlen(((audiodb_album**)res->buffer)[i]->str_albumthumb) != 0) {
      std::cout << "Albumthumb: "
                << ((audiodb_album**)res->buffer)[i]->str_albumthumb
                << std::endl;
    }
    if (((audiodb_album**)res->buffer)[i]->str_albumthumbback != NULL &&
        strlen(((audiodb_album**)res->buffer)[i]->str_albumthumbback) != 0) {
      std::cout << "Albumthumbback: "
                << ((audiodb_album**)res->buffer)[i]->str_albumthumbback
                << std::endl;
    }
    if (((audiodb_album**)res->buffer)[i]->str_albumthumbhq != NULL &&
        strlen(((audiodb_album**)res->buffer)[i]->str_albumthumbhq) != 0) {
      std::cout << "Albumthumbhq: "
                << ((audiodb_album**)res->buffer)[i]->str_albumthumbhq
                << std::endl;
    }
    if (((audiodb_album**)res->buffer)[i]->str_allmusicid != NULL &&
        strlen(((audiodb_album**)res->buffer)[i]->str_allmusicid) != 0) {
      std::cout << "Allmusicid: "
                << ((audiodb_album**)res->buffer)[i]->str_allmusicid
                << std::endl;
    }
    if (((audiodb_album**)res->buffer)[i]->str_amazonid != NULL &&
        strlen(((audiodb_album**)res->buffer)[i]->str_amazonid) != 0) {
      std::cout << "Amazonid: "
                << ((audiodb_album**)res->buffer)[i]->str_amazonid << std::endl;
    }
    if (((audiodb_album**)res->buffer)[i]->str_artist != NULL &&
        strlen(((audiodb_album**)res->buffer)[i]->str_artist) != 0) {
      std::cout << "Artist: " << ((audiodb_album**)res->buffer)[i]->str_artist
                << std::endl;
    }
    if (((audiodb_album**)res->buffer)[i]->str_artist_stripped != NULL &&
        strlen(((audiodb_album**)res->buffer)[i]->str_artist_stripped) != 0) {
      std::cout << "Artist_stripped: "
                << ((audiodb_album**)res->buffer)[i]->str_artist_stripped
                << std::endl;
    }
    if (((audiodb_album**)res->buffer)[i]->str_bbcreviewid != NULL &&
        strlen(((audiodb_album**)res->buffer)[i]->str_bbcreviewid) != 0) {
      std::cout << "Bbcreviewid: "
                << ((audiodb_album**)res->buffer)[i]->str_bbcreviewid
                << std::endl;
    }
    if (((audiodb_album**)res->buffer)[i]->str_description != NULL &&
        strlen(((audiodb_album**)res->buffer)[i]->str_description) != 0) {
      std::cout << "Description: "
                << ((audiodb_album**)res->buffer)[i]->str_description
                << std::endl;
    }
    if (((audiodb_album**)res->buffer)[i]->str_descriptioncn != NULL &&
        strlen(((audiodb_album**)res->buffer)[i]->str_descriptioncn) != 0) {
      std::cout << "Descriptioncn: "
                << ((audiodb_album**)res->buffer)[i]->str_descriptioncn
                << std::endl;
    }
    if (((audiodb_album**)res->buffer)[i]->str_descriptionde != NULL &&
        strlen(((audiodb_album**)res->buffer)[i]->str_descriptionde) != 0) {
      std::cout << "Descriptionde: "
                << ((audiodb_album**)res->buffer)[i]->str_descriptionde
                << std::endl;
    }
    if (((audiodb_album**)res->buffer)[i]->str_descriptionen != NULL &&
        strlen(((audiodb_album**)res->buffer)[i]->str_descriptionen) != 0) {
      std::cout << "Descriptionen: "
                << ((audiodb_album**)res->buffer)[i]->str_descriptionen
                << std::endl;
    }
    if (((audiodb_album**)res->buffer)[i]->str_descriptiones != NULL &&
        strlen(((audiodb_album**)res->buffer)[i]->str_descriptiones) != 0) {
      std::cout << "Descriptiones: "
                << ((audiodb_album**)res->buffer)[i]->str_descriptiones
                << std::endl;
    }
    if (((audiodb_album**)res->buffer)[i]->str_descriptionfr != NULL &&
        strlen(((audiodb_album**)res->buffer)[i]->str_descriptionfr) != 0) {
      std::cout << "Descriptionfr: "
                << ((audiodb_album**)res->buffer)[i]->str_descriptionfr
                << std::endl;
    }
    if (((audiodb_album**)res->buffer)[i]->str_descriptionhu != NULL &&
        strlen(((audiodb_album**)res->buffer)[i]->str_descriptionhu) != 0) {
      std::cout << "Descriptionhu: "
                << ((audiodb_album**)res->buffer)[i]->str_descriptionhu
                << std::endl;
    }
    if (((audiodb_album**)res->buffer)[i]->str_descriptionil != NULL &&
        strlen(((audiodb_album**)res->buffer)[i]->str_descriptionil) != 0) {
      std::cout << "Descriptionil: "
                << ((audiodb_album**)res->buffer)[i]->str_descriptionil
                << std::endl;
    }
    if (((audiodb_album**)res->buffer)[i]->str_descriptionit != NULL &&
        strlen(((audiodb_album**)res->buffer)[i]->str_descriptionit) != 0) {
      std::cout << "Descriptionit: "
                << ((audiodb_album**)res->buffer)[i]->str_descriptionit
                << std::endl;
    }
    if (((audiodb_album**)res->buffer)[i]->str_descriptionjp != NULL &&
        strlen(((audiodb_album**)res->buffer)[i]->str_descriptionjp) != 0) {
      std::cout << "Descriptionjp: "
                << ((audiodb_album**)res->buffer)[i]->str_descriptionjp
                << std::endl;
    }
    if (((audiodb_album**)res->buffer)[i]->str_descriptionnl != NULL &&
        strlen(((audiodb_album**)res->buffer)[i]->str_descriptionnl) != 0) {
      std::cout << "Descriptionnl: "
                << ((audiodb_album**)res->buffer)[i]->str_descriptionnl
                << std::endl;
    }
    if (((audiodb_album**)res->buffer)[i]->str_descriptionno != NULL &&
        strlen(((audiodb_album**)res->buffer)[i]->str_descriptionno) != 0) {
      std::cout << "Descriptionno: "
                << ((audiodb_album**)res->buffer)[i]->str_descriptionno
                << std::endl;
    }
    if (((audiodb_album**)res->buffer)[i]->str_descriptionpl != NULL &&
        strlen(((audiodb_album**)res->buffer)[i]->str_descriptionpl) != 0) {
      std::cout << "Descriptionpl: "
                << ((audiodb_album**)res->buffer)[i]->str_descriptionpl
                << std::endl;
    }
    if (((audiodb_album**)res->buffer)[i]->str_descriptionpt != NULL &&
        strlen(((audiodb_album**)res->buffer)[i]->str_descriptionpt) != 0) {
      std::cout << "Descriptionpt: "
                << ((audiodb_album**)res->buffer)[i]->str_descriptionpt
                << std::endl;
    }
    if (((audiodb_album**)res->buffer)[i]->str_descriptionru != NULL &&
        strlen(((audiodb_album**)res->buffer)[i]->str_descriptionru) != 0) {
      std::cout << "Descriptionru: "
                << ((audiodb_album**)res->buffer)[i]->str_descriptionru
                << std::endl;
    }
    if (((audiodb_album**)res->buffer)[i]->str_descriptionse != NULL &&
        strlen(((audiodb_album**)res->buffer)[i]->str_descriptionse) != 0) {
      std::cout << "Descriptionse: "
                << ((audiodb_album**)res->buffer)[i]->str_descriptionse
                << std::endl;
    }
    if (((audiodb_album**)res->buffer)[i]->str_discogsid != NULL &&
        strlen(((audiodb_album**)res->buffer)[i]->str_discogsid) != 0) {
      std::cout << "Discogsid: "
                << ((audiodb_album**)res->buffer)[i]->str_discogsid
                << std::endl;
    }
    if (((audiodb_album**)res->buffer)[i]->str_geniusid != NULL &&
        strlen(((audiodb_album**)res->buffer)[i]->str_geniusid) != 0) {
      std::cout << "Geniusid: "
                << ((audiodb_album**)res->buffer)[i]->str_geniusid << std::endl;
    }
    if (((audiodb_album**)res->buffer)[i]->str_genre != NULL &&
        strlen(((audiodb_album**)res->buffer)[i]->str_genre) != 0) {
      std::cout << "Genre: " << ((audiodb_album**)res->buffer)[i]->str_genre
                << std::endl;
    }
    if (((audiodb_album**)res->buffer)[i]->str_itunesid != NULL &&
        strlen(((audiodb_album**)res->buffer)[i]->str_itunesid) != 0) {
      std::cout << "Itunesid: "
                << ((audiodb_album**)res->buffer)[i]->str_itunesid << std::endl;
    }
    if (((audiodb_album**)res->buffer)[i]->str_label != NULL &&
        strlen(((audiodb_album**)res->buffer)[i]->str_label) != 0) {
      std::cout << "Label: " << ((audiodb_album**)res->buffer)[i]->str_label
                << std::endl;
    }
    if (((audiodb_album**)res->buffer)[i]->str_location != NULL &&
        strlen(((audiodb_album**)res->buffer)[i]->str_location) != 0) {
      std::cout << "Location: "
                << ((audiodb_album**)res->buffer)[i]->str_location << std::endl;
    }
    if (((audiodb_album**)res->buffer)[i]->str_locked != NULL &&
        strlen(((audiodb_album**)res->buffer)[i]->str_locked) != 0) {
      std::cout << "Locked: " << ((audiodb_album**)res->buffer)[i]->str_locked
                << std::endl;
    }
    if (((audiodb_album**)res->buffer)[i]->str_lyricwikiid != NULL &&
        strlen(((audiodb_album**)res->buffer)[i]->str_lyricwikiid) != 0) {
      std::cout << "Lyricwikiid: "
                << ((audiodb_album**)res->buffer)[i]->str_lyricwikiid
                << std::endl;
    }
    if (((audiodb_album**)res->buffer)[i]->str_mood != NULL &&
        strlen(((audiodb_album**)res->buffer)[i]->str_mood) != 0) {
      std::cout << "Mood: " << ((audiodb_album**)res->buffer)[i]->str_mood
                << std::endl;
    }
    if (((audiodb_album**)res->buffer)[i]->str_music_brainz_artist_id != NULL &&
        strlen(((audiodb_album**)res->buffer)[i]->str_music_brainz_artist_id) !=
            0) {
      std::cout << "Music_brainz_artist_id: "
                << ((audiodb_album**)res->buffer)[i]->str_music_brainz_artist_id
                << std::endl;
    }
    if (((audiodb_album**)res->buffer)[i]->str_music_brainz_id != NULL &&
        strlen(((audiodb_album**)res->buffer)[i]->str_music_brainz_id) != 0) {
      std::cout << "Music_brainz_id: "
                << ((audiodb_album**)res->buffer)[i]->str_music_brainz_id
                << std::endl;
    }
    if (((audiodb_album**)res->buffer)[i]->str_musicmozid != NULL &&
        strlen(((audiodb_album**)res->buffer)[i]->str_musicmozid) != 0) {
      std::cout << "Musicmozid: "
                << ((audiodb_album**)res->buffer)[i]->str_musicmozid
                << std::endl;
    }
    if (((audiodb_album**)res->buffer)[i]->str_rate_your_music_id != NULL &&
        strlen(((audiodb_album**)res->buffer)[i]->str_rate_your_music_id) !=
            0) {
      std::cout << "Rate_your_music_id: "
                << ((audiodb_album**)res->buffer)[i]->str_rate_your_music_id
                << std::endl;
    }
    if (((audiodb_album**)res->buffer)[i]->str_release_format != NULL &&
        strlen(((audiodb_album**)res->buffer)[i]->str_release_format) != 0) {
      std::cout << "Release_format: "
                << ((audiodb_album**)res->buffer)[i]->str_release_format
                << std::endl;
    }
    if (((audiodb_album**)res->buffer)[i]->str_review != NULL &&
        strlen(((audiodb_album**)res->buffer)[i]->str_review) != 0) {
      std::cout << "Review: " << ((audiodb_album**)res->buffer)[i]->str_review
                << std::endl;
    }
    if (((audiodb_album**)res->buffer)[i]->str_speed != NULL &&
        strlen(((audiodb_album**)res->buffer)[i]->str_speed) != 0) {
      std::cout << "Speed: " << ((audiodb_album**)res->buffer)[i]->str_speed
                << std::endl;
    }
    if (((audiodb_album**)res->buffer)[i]->str_style != NULL &&
        strlen(((audiodb_album**)res->buffer)[i]->str_style) != 0) {
      std::cout << "Style: " << ((audiodb_album**)res->buffer)[i]->str_style
                << std::endl;
    }
    if (((audiodb_album**)res->buffer)[i]->str_theme != NULL &&
        strlen(((audiodb_album**)res->buffer)[i]->str_theme) != 0) {
      std::cout << "Theme: " << ((audiodb_album**)res->buffer)[i]->str_theme
                << std::endl;
    }
    if (((audiodb_album**)res->buffer)[i]->str_wikidataid != NULL &&
        strlen(((audiodb_album**)res->buffer)[i]->str_wikidataid) != 0) {
      std::cout << "Wikidataid: "
                << ((audiodb_album**)res->buffer)[i]->str_wikidataid
                << std::endl;
    }
    if (((audiodb_album**)res->buffer)[i]->str_wikipediaid != NULL &&
        strlen(((audiodb_album**)res->buffer)[i]->str_wikipediaid) != 0) {
      std::cout << "Wikipediaid: "
                << ((audiodb_album**)res->buffer)[i]->str_wikipediaid
                << std::endl;
    }
  }

  audiodb_albums_clean((audiodb_album**)res->buffer, res->buffer_length);
}

void search_track_id(char* s) {
  audiodb* res = audiodb_search_track_by_id(atoi(s));
  if (res->error != NULL) {
    fprintf(stderr, "Something went wrong: No results found\n");
    free(res->error);
    exit(1);
  }

  if (((audiodb_track*)res->buffer)->id_album != NULL &&
      strlen(((audiodb_track*)res->buffer)->id_album) != 0) {
    std::cout << "Album: " << ((audiodb_track*)res->buffer)->id_album
              << std::endl;
  }
  if (((audiodb_track*)res->buffer)->id_artist != NULL &&
      strlen(((audiodb_track*)res->buffer)->id_artist) != 0) {
    std::cout << "Artist: " << ((audiodb_track*)res->buffer)->id_artist
              << std::endl;
  }
  if (((audiodb_track*)res->buffer)->id_imvdb != NULL &&
      strlen(((audiodb_track*)res->buffer)->id_imvdb) != 0) {
    std::cout << "Imvdb: " << ((audiodb_track*)res->buffer)->id_imvdb
              << std::endl;
  }
  if (((audiodb_track*)res->buffer)->id_lyric != NULL &&
      strlen(((audiodb_track*)res->buffer)->id_lyric) != 0) {
    std::cout << "Lyric: " << ((audiodb_track*)res->buffer)->id_lyric
              << std::endl;
  }
  if (((audiodb_track*)res->buffer)->id_track != NULL &&
      strlen(((audiodb_track*)res->buffer)->id_track) != 0) {
    std::cout << "Track: " << ((audiodb_track*)res->buffer)->id_track
              << std::endl;
  }
  if (((audiodb_track*)res->buffer)->int_cd != NULL &&
      strlen(((audiodb_track*)res->buffer)->int_cd) != 0) {
    std::cout << "Cd: " << ((audiodb_track*)res->buffer)->int_cd << std::endl;
  }
  if (((audiodb_track*)res->buffer)->int_duration != NULL &&
      strlen(((audiodb_track*)res->buffer)->int_duration) != 0) {
    std::cout << "Duration: " << ((audiodb_track*)res->buffer)->int_duration
              << std::endl;
  }
  if (((audiodb_track*)res->buffer)->int_loved != NULL &&
      strlen(((audiodb_track*)res->buffer)->int_loved) != 0) {
    std::cout << "Loved: " << ((audiodb_track*)res->buffer)->int_loved
              << std::endl;
  }
  if (((audiodb_track*)res->buffer)->int_music_vid_comments != NULL &&
      strlen(((audiodb_track*)res->buffer)->int_music_vid_comments) != 0) {
    std::cout << "Music_vid_comments: "
              << ((audiodb_track*)res->buffer)->int_music_vid_comments
              << std::endl;
  }
  if (((audiodb_track*)res->buffer)->int_music_vid_dislikes != NULL &&
      strlen(((audiodb_track*)res->buffer)->int_music_vid_dislikes) != 0) {
    std::cout << "Music_vid_dislikes: "
              << ((audiodb_track*)res->buffer)->int_music_vid_dislikes
              << std::endl;
  }
  if (((audiodb_track*)res->buffer)->int_music_vid_favorites != NULL &&
      strlen(((audiodb_track*)res->buffer)->int_music_vid_favorites) != 0) {
    std::cout << "Music_vid_favorites: "
              << ((audiodb_track*)res->buffer)->int_music_vid_favorites
              << std::endl;
  }
  if (((audiodb_track*)res->buffer)->int_music_vid_likes != NULL &&
      strlen(((audiodb_track*)res->buffer)->int_music_vid_likes) != 0) {
    std::cout << "Music_vid_likes: "
              << ((audiodb_track*)res->buffer)->int_music_vid_likes
              << std::endl;
  }
  if (((audiodb_track*)res->buffer)->int_music_vid_views != NULL &&
      strlen(((audiodb_track*)res->buffer)->int_music_vid_views) != 0) {
    std::cout << "Music_vid_views: "
              << ((audiodb_track*)res->buffer)->int_music_vid_views
              << std::endl;
  }
  if (((audiodb_track*)res->buffer)->int_score != NULL &&
      strlen(((audiodb_track*)res->buffer)->int_score) != 0) {
    std::cout << "Score: " << ((audiodb_track*)res->buffer)->int_score
              << std::endl;
  }
  if (((audiodb_track*)res->buffer)->int_scorevotes != NULL &&
      strlen(((audiodb_track*)res->buffer)->int_scorevotes) != 0) {
    std::cout << "Scorevotes: " << ((audiodb_track*)res->buffer)->int_scorevotes
              << std::endl;
  }
  if (((audiodb_track*)res->buffer)->int_total_listeners != NULL &&
      strlen(((audiodb_track*)res->buffer)->int_total_listeners) != 0) {
    std::cout << "Total_listeners: "
              << ((audiodb_track*)res->buffer)->int_total_listeners
              << std::endl;
  }
  if (((audiodb_track*)res->buffer)->int_totalplays != NULL &&
      strlen(((audiodb_track*)res->buffer)->int_totalplays) != 0) {
    std::cout << "Totalplays: " << ((audiodb_track*)res->buffer)->int_totalplays
              << std::endl;
  }
  if (((audiodb_track*)res->buffer)->int_tracknumber != NULL &&
      strlen(((audiodb_track*)res->buffer)->int_tracknumber) != 0) {
    std::cout << "Tracknumber: "
              << ((audiodb_track*)res->buffer)->int_tracknumber << std::endl;
  }
  if (((audiodb_track*)res->buffer)->str_album != NULL &&
      strlen(((audiodb_track*)res->buffer)->str_album) != 0) {
    std::cout << "Album: " << ((audiodb_track*)res->buffer)->str_album
              << std::endl;
  }
  if (((audiodb_track*)res->buffer)->str_artist != NULL &&
      strlen(((audiodb_track*)res->buffer)->str_artist) != 0) {
    std::cout << "Artist: " << ((audiodb_track*)res->buffer)->str_artist
              << std::endl;
  }
  if (((audiodb_track*)res->buffer)->str_artist_alternate != NULL &&
      strlen(((audiodb_track*)res->buffer)->str_artist_alternate) != 0) {
    std::cout << "Artist_alternate: "
              << ((audiodb_track*)res->buffer)->str_artist_alternate
              << std::endl;
  }
  if (((audiodb_track*)res->buffer)->str_descriptioncn != NULL &&
      strlen(((audiodb_track*)res->buffer)->str_descriptioncn) != 0) {
    std::cout << "Descriptioncn: "
              << ((audiodb_track*)res->buffer)->str_descriptioncn << std::endl;
  }
  if (((audiodb_track*)res->buffer)->str_descriptionde != NULL &&
      strlen(((audiodb_track*)res->buffer)->str_descriptionde) != 0) {
    std::cout << "Descriptionde: "
              << ((audiodb_track*)res->buffer)->str_descriptionde << std::endl;
  }
  if (((audiodb_track*)res->buffer)->str_descriptionen != NULL &&
      strlen(((audiodb_track*)res->buffer)->str_descriptionen) != 0) {
    std::cout << "Descriptionen: "
              << ((audiodb_track*)res->buffer)->str_descriptionen << std::endl;
  }
  if (((audiodb_track*)res->buffer)->str_descriptiones != NULL &&
      strlen(((audiodb_track*)res->buffer)->str_descriptiones) != 0) {
    std::cout << "Descriptiones: "
              << ((audiodb_track*)res->buffer)->str_descriptiones << std::endl;
  }
  if (((audiodb_track*)res->buffer)->str_descriptionfr != NULL &&
      strlen(((audiodb_track*)res->buffer)->str_descriptionfr) != 0) {
    std::cout << "Descriptionfr: "
              << ((audiodb_track*)res->buffer)->str_descriptionfr << std::endl;
  }
  if (((audiodb_track*)res->buffer)->str_descriptionhu != NULL &&
      strlen(((audiodb_track*)res->buffer)->str_descriptionhu) != 0) {
    std::cout << "Descriptionhu: "
              << ((audiodb_track*)res->buffer)->str_descriptionhu << std::endl;
  }
  if (((audiodb_track*)res->buffer)->str_descriptionil != NULL &&
      strlen(((audiodb_track*)res->buffer)->str_descriptionil) != 0) {
    std::cout << "Descriptionil: "
              << ((audiodb_track*)res->buffer)->str_descriptionil << std::endl;
  }
  if (((audiodb_track*)res->buffer)->str_descriptionit != NULL &&
      strlen(((audiodb_track*)res->buffer)->str_descriptionit) != 0) {
    std::cout << "Descriptionit: "
              << ((audiodb_track*)res->buffer)->str_descriptionit << std::endl;
  }
  if (((audiodb_track*)res->buffer)->str_descriptionjp != NULL &&
      strlen(((audiodb_track*)res->buffer)->str_descriptionjp) != 0) {
    std::cout << "Descriptionjp: "
              << ((audiodb_track*)res->buffer)->str_descriptionjp << std::endl;
  }
  if (((audiodb_track*)res->buffer)->str_descriptionnl != NULL &&
      strlen(((audiodb_track*)res->buffer)->str_descriptionnl) != 0) {
    std::cout << "Descriptionnl: "
              << ((audiodb_track*)res->buffer)->str_descriptionnl << std::endl;
  }
  if (((audiodb_track*)res->buffer)->str_descriptionno != NULL &&
      strlen(((audiodb_track*)res->buffer)->str_descriptionno) != 0) {
    std::cout << "Descriptionno: "
              << ((audiodb_track*)res->buffer)->str_descriptionno << std::endl;
  }
  if (((audiodb_track*)res->buffer)->str_descriptionpl != NULL &&
      strlen(((audiodb_track*)res->buffer)->str_descriptionpl) != 0) {
    std::cout << "Descriptionpl: "
              << ((audiodb_track*)res->buffer)->str_descriptionpl << std::endl;
  }
  if (((audiodb_track*)res->buffer)->str_descriptionpt != NULL &&
      strlen(((audiodb_track*)res->buffer)->str_descriptionpt) != 0) {
    std::cout << "Descriptionpt: "
              << ((audiodb_track*)res->buffer)->str_descriptionpt << std::endl;
  }
  if (((audiodb_track*)res->buffer)->str_descriptionru != NULL &&
      strlen(((audiodb_track*)res->buffer)->str_descriptionru) != 0) {
    std::cout << "Descriptionru: "
              << ((audiodb_track*)res->buffer)->str_descriptionru << std::endl;
  }
  if (((audiodb_track*)res->buffer)->str_descriptionse != NULL &&
      strlen(((audiodb_track*)res->buffer)->str_descriptionse) != 0) {
    std::cout << "Descriptionse: "
              << ((audiodb_track*)res->buffer)->str_descriptionse << std::endl;
  }
  if (((audiodb_track*)res->buffer)->str_genre != NULL &&
      strlen(((audiodb_track*)res->buffer)->str_genre) != 0) {
    std::cout << "Genre: " << ((audiodb_track*)res->buffer)->str_genre
              << std::endl;
  }
  if (((audiodb_track*)res->buffer)->str_locked != NULL &&
      strlen(((audiodb_track*)res->buffer)->str_locked) != 0) {
    std::cout << "Locked: " << ((audiodb_track*)res->buffer)->str_locked
              << std::endl;
  }
  if (((audiodb_track*)res->buffer)->str_mood != NULL &&
      strlen(((audiodb_track*)res->buffer)->str_mood) != 0) {
    std::cout << "Mood: " << ((audiodb_track*)res->buffer)->str_mood
              << std::endl;
  }
  if (((audiodb_track*)res->buffer)->str_music_brainz_album_id != NULL &&
      strlen(((audiodb_track*)res->buffer)->str_music_brainz_album_id) != 0) {
    std::cout << "Music_brainz_album_id: "
              << ((audiodb_track*)res->buffer)->str_music_brainz_album_id
              << std::endl;
  }
  if (((audiodb_track*)res->buffer)->str_music_brainz_artist_id != NULL &&
      strlen(((audiodb_track*)res->buffer)->str_music_brainz_artist_id) != 0) {
    std::cout << "Music_brainz_artist_id: "
              << ((audiodb_track*)res->buffer)->str_music_brainz_artist_id
              << std::endl;
  }
  if (((audiodb_track*)res->buffer)->str_music_brainz_id != NULL &&
      strlen(((audiodb_track*)res->buffer)->str_music_brainz_id) != 0) {
    std::cout << "Music_brainz_id: "
              << ((audiodb_track*)res->buffer)->str_music_brainz_id
              << std::endl;
  }
  if (((audiodb_track*)res->buffer)->str_musicvid != NULL &&
      strlen(((audiodb_track*)res->buffer)->str_musicvid) != 0) {
    std::cout << "Musicvid: " << ((audiodb_track*)res->buffer)->str_musicvid
              << std::endl;
  }
  if (((audiodb_track*)res->buffer)->str_music_vid_company != NULL &&
      strlen(((audiodb_track*)res->buffer)->str_music_vid_company) != 0) {
    std::cout << "Music_vid_company: "
              << ((audiodb_track*)res->buffer)->str_music_vid_company
              << std::endl;
  }
  if (((audiodb_track*)res->buffer)->str_music_vid_director != NULL &&
      strlen(((audiodb_track*)res->buffer)->str_music_vid_director) != 0) {
    std::cout << "Music_vid_director: "
              << ((audiodb_track*)res->buffer)->str_music_vid_director
              << std::endl;
  }
  if (((audiodb_track*)res->buffer)->str_music_vid_screen1 != NULL &&
      strlen(((audiodb_track*)res->buffer)->str_music_vid_screen1) != 0) {
    std::cout << "Music_vid_screen1: "
              << ((audiodb_track*)res->buffer)->str_music_vid_screen1
              << std::endl;
  }
  if (((audiodb_track*)res->buffer)->str_music_vid_screen2 != NULL &&
      strlen(((audiodb_track*)res->buffer)->str_music_vid_screen2) != 0) {
    std::cout << "Music_vid_screen2: "
              << ((audiodb_track*)res->buffer)->str_music_vid_screen2
              << std::endl;
  }
  if (((audiodb_track*)res->buffer)->str_music_vid_screen3 != NULL &&
      strlen(((audiodb_track*)res->buffer)->str_music_vid_screen3) != 0) {
    std::cout << "Music_vid_screen3: "
              << ((audiodb_track*)res->buffer)->str_music_vid_screen3
              << std::endl;
  }
  if (((audiodb_track*)res->buffer)->str_style != NULL &&
      strlen(((audiodb_track*)res->buffer)->str_style) != 0) {
    std::cout << "Style: " << ((audiodb_track*)res->buffer)->str_style
              << std::endl;
  }
  if (((audiodb_track*)res->buffer)->str_theme != NULL &&
      strlen(((audiodb_track*)res->buffer)->str_theme) != 0) {
    std::cout << "Theme: " << ((audiodb_track*)res->buffer)->str_theme
              << std::endl;
  }
  if (((audiodb_track*)res->buffer)->str_track != NULL &&
      strlen(((audiodb_track*)res->buffer)->str_track) != 0) {
    std::cout << "Track: " << ((audiodb_track*)res->buffer)->str_track
              << std::endl;
  }
  if (((audiodb_track*)res->buffer)->str_track3dcase != NULL &&
      strlen(((audiodb_track*)res->buffer)->str_track3dcase) != 0) {
    std::cout << "Track3dcase: "
              << ((audiodb_track*)res->buffer)->str_track3dcase << std::endl;
  }
  if (((audiodb_track*)res->buffer)->str_tracklyrics != NULL &&
      strlen(((audiodb_track*)res->buffer)->str_tracklyrics) != 0) {
    std::cout << "Tracklyrics: "
              << ((audiodb_track*)res->buffer)->str_tracklyrics << std::endl;
  }
  if (((audiodb_track*)res->buffer)->str_trackthumb != NULL &&
      strlen(((audiodb_track*)res->buffer)->str_trackthumb) != 0) {
    std::cout << "Trackthumb: " << ((audiodb_track*)res->buffer)->str_trackthumb
              << std::endl;
  }

  audiodb_track_clean((audiodb_track*)res->buffer);
}

void search_tracks(char* s) {
  audiodb* res = audiodb_search_tracks_by_album_id(atoi(s));
  if (res->error != NULL) {
    fprintf(stderr, "Something went wrong: No results found\n");
    free(res->error);
    exit(1);
  }

  for (int i = 0; i < res->buffer_length; i++) {
    if (((audiodb_track**)res->buffer)[i]->id_album != NULL &&
        strlen(((audiodb_track**)res->buffer)[i]->id_album) != 0) {
      std::cout << "Album: " << ((audiodb_track**)res->buffer)[i]->id_album
                << std::endl;
    }
    if (((audiodb_track**)res->buffer)[i]->id_artist != NULL &&
        strlen(((audiodb_track**)res->buffer)[i]->id_artist) != 0) {
      std::cout << "Artist: " << ((audiodb_track**)res->buffer)[i]->id_artist
                << std::endl;
    }
    if (((audiodb_track**)res->buffer)[i]->id_imvdb != NULL &&
        strlen(((audiodb_track**)res->buffer)[i]->id_imvdb) != 0) {
      std::cout << "Imvdb: " << ((audiodb_track**)res->buffer)[i]->id_imvdb
                << std::endl;
    }
    if (((audiodb_track**)res->buffer)[i]->id_lyric != NULL &&
        strlen(((audiodb_track**)res->buffer)[i]->id_lyric) != 0) {
      std::cout << "Lyric: " << ((audiodb_track**)res->buffer)[i]->id_lyric
                << std::endl;
    }
    if (((audiodb_track**)res->buffer)[i]->id_track != NULL &&
        strlen(((audiodb_track**)res->buffer)[i]->id_track) != 0) {
      std::cout << "Track: " << ((audiodb_track**)res->buffer)[i]->id_track
                << std::endl;
    }
    if (((audiodb_track**)res->buffer)[i]->int_cd != NULL &&
        strlen(((audiodb_track**)res->buffer)[i]->int_cd) != 0) {
      std::cout << "Cd: " << ((audiodb_track**)res->buffer)[i]->int_cd
                << std::endl;
    }
    if (((audiodb_track**)res->buffer)[i]->int_duration != NULL &&
        strlen(((audiodb_track**)res->buffer)[i]->int_duration) != 0) {
      std::cout << "Duration: "
                << ((audiodb_track**)res->buffer)[i]->int_duration << std::endl;
    }
    if (((audiodb_track**)res->buffer)[i]->int_loved != NULL &&
        strlen(((audiodb_track**)res->buffer)[i]->int_loved) != 0) {
      std::cout << "Loved: " << ((audiodb_track**)res->buffer)[i]->int_loved
                << std::endl;
    }
    if (((audiodb_track**)res->buffer)[i]->int_music_vid_comments != NULL &&
        strlen(((audiodb_track**)res->buffer)[i]->int_music_vid_comments) !=
            0) {
      std::cout << "Music_vid_comments: "
                << ((audiodb_track**)res->buffer)[i]->int_music_vid_comments
                << std::endl;
    }
    if (((audiodb_track**)res->buffer)[i]->int_music_vid_dislikes != NULL &&
        strlen(((audiodb_track**)res->buffer)[i]->int_music_vid_dislikes) !=
            0) {
      std::cout << "Music_vid_dislikes: "
                << ((audiodb_track**)res->buffer)[i]->int_music_vid_dislikes
                << std::endl;
    }
    if (((audiodb_track**)res->buffer)[i]->int_music_vid_favorites != NULL &&
        strlen(((audiodb_track**)res->buffer)[i]->int_music_vid_favorites) !=
            0) {
      std::cout << "Music_vid_favorites: "
                << ((audiodb_track**)res->buffer)[i]->int_music_vid_favorites
                << std::endl;
    }
    if (((audiodb_track**)res->buffer)[i]->int_music_vid_likes != NULL &&
        strlen(((audiodb_track**)res->buffer)[i]->int_music_vid_likes) != 0) {
      std::cout << "Music_vid_likes: "
                << ((audiodb_track**)res->buffer)[i]->int_music_vid_likes
                << std::endl;
    }
    if (((audiodb_track**)res->buffer)[i]->int_music_vid_views != NULL &&
        strlen(((audiodb_track**)res->buffer)[i]->int_music_vid_views) != 0) {
      std::cout << "Music_vid_views: "
                << ((audiodb_track**)res->buffer)[i]->int_music_vid_views
                << std::endl;
    }
    if (((audiodb_track**)res->buffer)[i]->int_score != NULL &&
        strlen(((audiodb_track**)res->buffer)[i]->int_score) != 0) {
      std::cout << "Score: " << ((audiodb_track**)res->buffer)[i]->int_score
                << std::endl;
    }
    if (((audiodb_track**)res->buffer)[i]->int_scorevotes != NULL &&
        strlen(((audiodb_track**)res->buffer)[i]->int_scorevotes) != 0) {
      std::cout << "Scorevotes: "
                << ((audiodb_track**)res->buffer)[i]->int_scorevotes
                << std::endl;
    }
    if (((audiodb_track**)res->buffer)[i]->int_total_listeners != NULL &&
        strlen(((audiodb_track**)res->buffer)[i]->int_total_listeners) != 0) {
      std::cout << "Total_listeners: "
                << ((audiodb_track**)res->buffer)[i]->int_total_listeners
                << std::endl;
    }
    if (((audiodb_track**)res->buffer)[i]->int_totalplays != NULL &&
        strlen(((audiodb_track**)res->buffer)[i]->int_totalplays) != 0) {
      std::cout << "Totalplays: "
                << ((audiodb_track**)res->buffer)[i]->int_totalplays
                << std::endl;
    }
    if (((audiodb_track**)res->buffer)[i]->int_tracknumber != NULL &&
        strlen(((audiodb_track**)res->buffer)[i]->int_tracknumber) != 0) {
      std::cout << "Tracknumber: "
                << ((audiodb_track**)res->buffer)[i]->int_tracknumber
                << std::endl;
    }
    if (((audiodb_track**)res->buffer)[i]->str_album != NULL &&
        strlen(((audiodb_track**)res->buffer)[i]->str_album) != 0) {
      std::cout << "Album: " << ((audiodb_track**)res->buffer)[i]->str_album
                << std::endl;
    }
    if (((audiodb_track**)res->buffer)[i]->str_artist != NULL &&
        strlen(((audiodb_track**)res->buffer)[i]->str_artist) != 0) {
      std::cout << "Artist: " << ((audiodb_track**)res->buffer)[i]->str_artist
                << std::endl;
    }
    if (((audiodb_track**)res->buffer)[i]->str_artist_alternate != NULL &&
        strlen(((audiodb_track**)res->buffer)[i]->str_artist_alternate) != 0) {
      std::cout << "Artist_alternate: "
                << ((audiodb_track**)res->buffer)[i]->str_artist_alternate
                << std::endl;
    }
    if (((audiodb_track**)res->buffer)[i]->str_descriptioncn != NULL &&
        strlen(((audiodb_track**)res->buffer)[i]->str_descriptioncn) != 0) {
      std::cout << "Descriptioncn: "
                << ((audiodb_track**)res->buffer)[i]->str_descriptioncn
                << std::endl;
    }
    if (((audiodb_track**)res->buffer)[i]->str_descriptionde != NULL &&
        strlen(((audiodb_track**)res->buffer)[i]->str_descriptionde) != 0) {
      std::cout << "Descriptionde: "
                << ((audiodb_track**)res->buffer)[i]->str_descriptionde
                << std::endl;
    }
    if (((audiodb_track**)res->buffer)[i]->str_descriptionen != NULL &&
        strlen(((audiodb_track**)res->buffer)[i]->str_descriptionen) != 0) {
      std::cout << "Descriptionen: "
                << ((audiodb_track**)res->buffer)[i]->str_descriptionen
                << std::endl;
    }
    if (((audiodb_track**)res->buffer)[i]->str_descriptiones != NULL &&
        strlen(((audiodb_track**)res->buffer)[i]->str_descriptiones) != 0) {
      std::cout << "Descriptiones: "
                << ((audiodb_track**)res->buffer)[i]->str_descriptiones
                << std::endl;
    }
    if (((audiodb_track**)res->buffer)[i]->str_descriptionfr != NULL &&
        strlen(((audiodb_track**)res->buffer)[i]->str_descriptionfr) != 0) {
      std::cout << "Descriptionfr: "
                << ((audiodb_track**)res->buffer)[i]->str_descriptionfr
                << std::endl;
    }
    if (((audiodb_track**)res->buffer)[i]->str_descriptionhu != NULL &&
        strlen(((audiodb_track**)res->buffer)[i]->str_descriptionhu) != 0) {
      std::cout << "Descriptionhu: "
                << ((audiodb_track**)res->buffer)[i]->str_descriptionhu
                << std::endl;
    }
    if (((audiodb_track**)res->buffer)[i]->str_descriptionil != NULL &&
        strlen(((audiodb_track**)res->buffer)[i]->str_descriptionil) != 0) {
      std::cout << "Descriptionil: "
                << ((audiodb_track**)res->buffer)[i]->str_descriptionil
                << std::endl;
    }
    if (((audiodb_track**)res->buffer)[i]->str_descriptionit != NULL &&
        strlen(((audiodb_track**)res->buffer)[i]->str_descriptionit) != 0) {
      std::cout << "Descriptionit: "
                << ((audiodb_track**)res->buffer)[i]->str_descriptionit
                << std::endl;
    }
    if (((audiodb_track**)res->buffer)[i]->str_descriptionjp != NULL &&
        strlen(((audiodb_track**)res->buffer)[i]->str_descriptionjp) != 0) {
      std::cout << "Descriptionjp: "
                << ((audiodb_track**)res->buffer)[i]->str_descriptionjp
                << std::endl;
    }
    if (((audiodb_track**)res->buffer)[i]->str_descriptionnl != NULL &&
        strlen(((audiodb_track**)res->buffer)[i]->str_descriptionnl) != 0) {
      std::cout << "Descriptionnl: "
                << ((audiodb_track**)res->buffer)[i]->str_descriptionnl
                << std::endl;
    }
    if (((audiodb_track**)res->buffer)[i]->str_descriptionno != NULL &&
        strlen(((audiodb_track**)res->buffer)[i]->str_descriptionno) != 0) {
      std::cout << "Descriptionno: "
                << ((audiodb_track**)res->buffer)[i]->str_descriptionno
                << std::endl;
    }
    if (((audiodb_track**)res->buffer)[i]->str_descriptionpl != NULL &&
        strlen(((audiodb_track**)res->buffer)[i]->str_descriptionpl) != 0) {
      std::cout << "Descriptionpl: "
                << ((audiodb_track**)res->buffer)[i]->str_descriptionpl
                << std::endl;
    }
    if (((audiodb_track**)res->buffer)[i]->str_descriptionpt != NULL &&
        strlen(((audiodb_track**)res->buffer)[i]->str_descriptionpt) != 0) {
      std::cout << "Descriptionpt: "
                << ((audiodb_track**)res->buffer)[i]->str_descriptionpt
                << std::endl;
    }
    if (((audiodb_track**)res->buffer)[i]->str_descriptionru != NULL &&
        strlen(((audiodb_track**)res->buffer)[i]->str_descriptionru) != 0) {
      std::cout << "Descriptionru: "
                << ((audiodb_track**)res->buffer)[i]->str_descriptionru
                << std::endl;
    }
    if (((audiodb_track**)res->buffer)[i]->str_descriptionse != NULL &&
        strlen(((audiodb_track**)res->buffer)[i]->str_descriptionse) != 0) {
      std::cout << "Descriptionse: "
                << ((audiodb_track**)res->buffer)[i]->str_descriptionse
                << std::endl;
    }
    if (((audiodb_track**)res->buffer)[i]->str_genre != NULL &&
        strlen(((audiodb_track**)res->buffer)[i]->str_genre) != 0) {
      std::cout << "Genre: " << ((audiodb_track**)res->buffer)[i]->str_genre
                << std::endl;
    }
    if (((audiodb_track**)res->buffer)[i]->str_locked != NULL &&
        strlen(((audiodb_track**)res->buffer)[i]->str_locked) != 0) {
      std::cout << "Locked: " << ((audiodb_track**)res->buffer)[i]->str_locked
                << std::endl;
    }
    if (((audiodb_track**)res->buffer)[i]->str_mood != NULL &&
        strlen(((audiodb_track**)res->buffer)[i]->str_mood) != 0) {
      std::cout << "Mood: " << ((audiodb_track**)res->buffer)[i]->str_mood
                << std::endl;
    }
    if (((audiodb_track**)res->buffer)[i]->str_music_brainz_album_id != NULL &&
        strlen(((audiodb_track**)res->buffer)[i]->str_music_brainz_album_id) !=
            0) {
      std::cout << "Music_brainz_album_id: "
                << ((audiodb_track**)res->buffer)[i]->str_music_brainz_album_id
                << std::endl;
    }
    if (((audiodb_track**)res->buffer)[i]->str_music_brainz_artist_id != NULL &&
        strlen(((audiodb_track**)res->buffer)[i]->str_music_brainz_artist_id) !=
            0) {
      std::cout << "Music_brainz_artist_id: "
                << ((audiodb_track**)res->buffer)[i]->str_music_brainz_artist_id
                << std::endl;
    }
    if (((audiodb_track**)res->buffer)[i]->str_music_brainz_id != NULL &&
        strlen(((audiodb_track**)res->buffer)[i]->str_music_brainz_id) != 0) {
      std::cout << "Music_brainz_id: "
                << ((audiodb_track**)res->buffer)[i]->str_music_brainz_id
                << std::endl;
    }
    if (((audiodb_track**)res->buffer)[i]->str_musicvid != NULL &&
        strlen(((audiodb_track**)res->buffer)[i]->str_musicvid) != 0) {
      std::cout << "Musicvid: "
                << ((audiodb_track**)res->buffer)[i]->str_musicvid << std::endl;
    }
    if (((audiodb_track**)res->buffer)[i]->str_music_vid_company != NULL &&
        strlen(((audiodb_track**)res->buffer)[i]->str_music_vid_company) != 0) {
      std::cout << "Music_vid_company: "
                << ((audiodb_track**)res->buffer)[i]->str_music_vid_company
                << std::endl;
    }
    if (((audiodb_track**)res->buffer)[i]->str_music_vid_director != NULL &&
        strlen(((audiodb_track**)res->buffer)[i]->str_music_vid_director) !=
            0) {
      std::cout << "Music_vid_director: "
                << ((audiodb_track**)res->buffer)[i]->str_music_vid_director
                << std::endl;
    }
    if (((audiodb_track**)res->buffer)[i]->str_music_vid_screen1 != NULL &&
        strlen(((audiodb_track**)res->buffer)[i]->str_music_vid_screen1) != 0) {
      std::cout << "Music_vid_screen1: "
                << ((audiodb_track**)res->buffer)[i]->str_music_vid_screen1
                << std::endl;
    }
    if (((audiodb_track**)res->buffer)[i]->str_music_vid_screen2 != NULL &&
        strlen(((audiodb_track**)res->buffer)[i]->str_music_vid_screen2) != 0) {
      std::cout << "Music_vid_screen2: "
                << ((audiodb_track**)res->buffer)[i]->str_music_vid_screen2
                << std::endl;
    }
    if (((audiodb_track**)res->buffer)[i]->str_music_vid_screen3 != NULL &&
        strlen(((audiodb_track**)res->buffer)[i]->str_music_vid_screen3) != 0) {
      std::cout << "Music_vid_screen3: "
                << ((audiodb_track**)res->buffer)[i]->str_music_vid_screen3
                << std::endl;
    }
    if (((audiodb_track**)res->buffer)[i]->str_style != NULL &&
        strlen(((audiodb_track**)res->buffer)[i]->str_style) != 0) {
      std::cout << "Style: " << ((audiodb_track**)res->buffer)[i]->str_style
                << std::endl;
    }
    if (((audiodb_track**)res->buffer)[i]->str_theme != NULL &&
        strlen(((audiodb_track**)res->buffer)[i]->str_theme) != 0) {
      std::cout << "Theme: " << ((audiodb_track**)res->buffer)[i]->str_theme
                << std::endl;
    }
    if (((audiodb_track**)res->buffer)[i]->str_track != NULL &&
        strlen(((audiodb_track**)res->buffer)[i]->str_track) != 0) {
      std::cout << "Track: " << ((audiodb_track**)res->buffer)[i]->str_track
                << std::endl;
    }
    if (((audiodb_track**)res->buffer)[i]->str_track3dcase != NULL &&
        strlen(((audiodb_track**)res->buffer)[i]->str_track3dcase) != 0) {
      std::cout << "Track3dcase: "
                << ((audiodb_track**)res->buffer)[i]->str_track3dcase
                << std::endl;
    }
    if (((audiodb_track**)res->buffer)[i]->str_tracklyrics != NULL &&
        strlen(((audiodb_track**)res->buffer)[i]->str_tracklyrics) != 0) {
      std::cout << "Tracklyrics: "
                << ((audiodb_track**)res->buffer)[i]->str_tracklyrics
                << std::endl;
    }
    if (((audiodb_track**)res->buffer)[i]->str_trackthumb != NULL &&
        strlen(((audiodb_track**)res->buffer)[i]->str_trackthumb) != 0) {
      std::cout << "Trackthumb: "
                << ((audiodb_track**)res->buffer)[i]->str_trackthumb
                << std::endl;
    }
  }

  audiodb_tracks_clean((audiodb_track**)res->buffer, res->buffer_length);
}

void search_music_videos(char* s) {
  audiodb* res = audiodb_search_music_videos_by_artist_id(atoi(s));
  if (res->error != NULL) {
    fprintf(stderr, "Something went wrong: No results found\n");
    free(res->error);
    exit(1);
  }

  for (int i = 0; i < res->buffer_length; i++) {
    if (((audiodb_music_video**)res->buffer)[i]->id_album != NULL &&
        strlen(((audiodb_music_video**)res->buffer)[i]->id_album) != 0) {
      std::cout << "Album: "
                << ((audiodb_music_video**)res->buffer)[i]->id_album
                << std::endl;
    }
    if (((audiodb_music_video**)res->buffer)[i]->id_artist != NULL &&
        strlen(((audiodb_music_video**)res->buffer)[i]->id_artist) != 0) {
      std::cout << "Artist: "
                << ((audiodb_music_video**)res->buffer)[i]->id_artist
                << std::endl;
    }
    if (((audiodb_music_video**)res->buffer)[i]->id_track != NULL &&
        strlen(((audiodb_music_video**)res->buffer)[i]->id_track) != 0) {
      std::cout << "Track: "
                << ((audiodb_music_video**)res->buffer)[i]->id_track
                << std::endl;
    }
    if (((audiodb_music_video**)res->buffer)[i]->str_descriptionen != NULL &&
        strlen(((audiodb_music_video**)res->buffer)[i]->str_descriptionen) !=
            0) {
      std::cout << "Descriptionen: "
                << ((audiodb_music_video**)res->buffer)[i]->str_descriptionen
                << std::endl;
    }
    if (((audiodb_music_video**)res->buffer)[i]->str_musicvid != NULL &&
        strlen(((audiodb_music_video**)res->buffer)[i]->str_musicvid) != 0) {
      std::cout << "Musicvid: "
                << ((audiodb_music_video**)res->buffer)[i]->str_musicvid
                << std::endl;
    }
    if (((audiodb_music_video**)res->buffer)[i]->str_track != NULL &&
        strlen(((audiodb_music_video**)res->buffer)[i]->str_track) != 0) {
      std::cout << "Track: "
                << ((audiodb_music_video**)res->buffer)[i]->str_track
                << std::endl;
    }
    if (((audiodb_music_video**)res->buffer)[i]->str_trackthumb != NULL &&
        strlen(((audiodb_music_video**)res->buffer)[i]->str_trackthumb) != 0) {
      std::cout << "Trackthumb: "
                << ((audiodb_music_video**)res->buffer)[i]->str_trackthumb
                << std::endl;
    }
  }

  audiodb_music_video_clean((audiodb_music_video**)res->buffer,
                            res->buffer_length);
}

int main(int argc, char** argv) {
  if (!index_exists(argc, 1)) {
    usage();
    exit(0);
  }

  if (strcmp(argv[FLAG], "-d") == 0) {
    if (!index_exists(argc, 2)) {
      fprintf(stderr, "Error: missing artist name\n");
      exit(1);
    }
    discography(argv[2]);
  } else if (strcmp(argv[FLAG], "--artist") == 0) {
    if (!index_exists(argc, 2)) {
      fprintf(stderr, "Error: missing artist name\n");
      exit(1);
    }
    search_artist(argv[2]);
  } else if (strcmp(argv[FLAG], "--artist-id") == 0) {
    if (!index_exists(argc, 2)) {
      fprintf(stderr, "Error: missing artist id\n");
      exit(1);
    }
    search_artist_id(argv[2]);
  } else if (strcmp(argv[FLAG], "--album-id") == 0) {
    if (!index_exists(argc, 2)) {
      fprintf(stderr, "Error: missing album id\n");
      exit(1);
    }
    search_album_id(argv[2]);
  } else if (strcmp(argv[FLAG], "--albums-artist-id") == 0) {
    if (!index_exists(argc, 2)) {
      fprintf(stderr, "Error: missing artist id\n");
      exit(1);
    }
    search_albums(argv[2]);
  } else if (strcmp(argv[FLAG], "--track-id") == 0) {
    if (!index_exists(argc, 2)) {
      fprintf(stderr, "Error: missing track id\n");
      exit(1);
    }
    search_track_id(argv[2]);
  } else if (strcmp(argv[FLAG], "--tracks-album-id") == 0) {
    if (!index_exists(argc, 2)) {
      fprintf(stderr, "Error: missing album id\n");
      exit(1);
    }
    search_tracks(argv[2]);
  } else if (strcmp(argv[FLAG], "--mv-artist-id") == 0) {
    if (!index_exists(argc, 2)) {
      fprintf(stderr, "Error: missing artist id\n");
      exit(1);
    }
    search_music_videos(argv[2]);
  } else {
    fprintf(stderr, "Error: %s unknown flag\n", argv[1]);
    exit(1);
  }
  return 0;
}