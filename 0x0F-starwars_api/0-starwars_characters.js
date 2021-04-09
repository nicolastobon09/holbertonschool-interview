#!/usr/bin/node

const request = require('request');
const ID = process.argv[2];
const URL_API = `https://swapi-api.hbtn.io/api/films/${ID}`;

const getDataFromApi = async (url) => {
  return new Promise((resolve, reject) => {
    request(url, function (error, response, body) {
      if (error) reject(error);
      else resolve(JSON.parse(body));
    });
  });
};

const displayData = async (url) => {
  const { characters } = await getDataFromApi(url);
  for (const character of characters) {
    const { name } = await getDataFromApi(character);
    console.log(name);
  }
};

displayData(URL_API);
