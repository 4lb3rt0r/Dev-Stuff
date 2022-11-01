// Import the functions you need from the SDKs you need
import { initializeApp } from "firebase/app";
import { getFirestore, collection } from 'firebase/firestore'
import { getAuth } from "firebase/auth";
import firebase from 'firebase/compat/app';
import 'firebase/compat/storage';

// Your web app's Firebase configuration
const firebaseConfig = {
  apiKey: "AIzaSyCJ-eY-6dz7VRYTJQJL4sF4TfCGp_cVl5Q",
  authDomain: "walmart-web-27610.firebaseapp.com",
  projectId: "walmart-web-27610",
  storageBucket: "walmart-web-27610.appspot.com",
  messagingSenderId: "807090400387",
  appId: "1:807090400387:web:e04c265d664d89d2d77fb6"
};

// Initialize Firebase
firebase.initializeApp(firebaseConfig);

const app = initializeApp(firebaseConfig);
const db = getFirestore(app);
const productsCollection = collection(db, 'products');
const auth = getAuth();

var storage = firebase.storage();

export { db, auth, storage };

export default productsCollection;
