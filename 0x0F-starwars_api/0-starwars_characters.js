#!/usr/bin/node

const request = require('request');
const ID = process.argv[2];
const URL = `https://swapi-api.hbtn.io/api/films/${ID}`;

function getCharactersByFilms () {
  request(URL, function (error, response, body) {
    if (error) return;
    if (response.statusCode !== 200) return;
    const data = JSON.parse(body);
    getNameCharactersByfimls(data.characters, 0);
  });
}

function getNameCharactersByfimls (characters, index) {
  if (characters.length === index) return;
  request(characters[index], function (error, response, body) {
    if (error) return;
    if (response.statusCode !== 200) return;
    const data = JSON.parse(body);
    console.log(data.name);
    index++;
    getNameCharactersByfimls(characters, index);
  });
}

getCharactersByFilms();
